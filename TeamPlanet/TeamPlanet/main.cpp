//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//システム系のヘッダーインクルード-----------
#include <stdio.h>
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
#include <process.h>

//Gameシステム用ヘッダー(自作)インクルード---
#include "WindowCreate.h"
#include "DeviceCreate.h"
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"
#include "Collision.h"

#include "EnemyData.h"

//オブジェクトヘッダ---------------
#include "Hero.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include "Select.h"
#include "Heart.h"
#include "Title.h"

//削除されていないメモリを出力にダンプする---
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)

#define new DBG_NEW
#endif
#endif	// _DEBUG

//LIBの登録--------------
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3dCompiler.lib")

//構造体-----------------

//グローバル変数---------
bool g_ls_game_end = false;	//スレッド用ゲーム終了フラグ
//int g_SceneChange = STAGESELECT;//ゲーム画面フラグ(test用)
int g_SceneChange = TITLE;//ゲーム画面フラグ
bool g_key_flag = true;//キーフラグ
extern ENEMYDATA e_data[ENEMY_NUM];

bool m_hit; //ハートに渡す用
int heart_num = 5; //ハートの数

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//ウィンドウプロジーシャー

//マルチスレッドにする関数-
//テクスチャ読み込み関数
unsigned __stdcall TextureLoadSled(void *p)
{
	//イメージ読み込み
	//主人公
	Draw::LoadImage(0, L"image\\Space ship.png");
	Draw::LoadImage(1, L"image\\bullet.png");
	Draw::LoadImage(12, L"image\\Space ship 1.png");
	Draw::LoadImage(13, L"image\\Space ship 2.png");
	Draw::LoadImage(14, L"image\\Space ship fire.png");
	Draw::LoadImage(15, L"image\\life.png");

	//敵
	Draw::LoadImage(2, L"image\\dust.png");
	Draw::LoadImage(3, L"image\\meteorite1.png");
	Draw::LoadImage(10, L"image\\enemy1.png");
	Draw::LoadImage(11, L"image\\enemy2.png");
	Draw::LoadImage(16, L"image\\satellite.png");
	Draw::LoadImage(17, L"image\\solar.png");
	Draw::LoadImage(18, L"image\\antenna.png");
	Draw::LoadImage(19, L"image\\meteorite2.png");
	Draw::LoadImage(20, L"image\\bulletE.png");

	//爆発エフェクト
	Draw::LoadImage(21, L"image\\boom1.png");
	Draw::LoadImage(22, L"image\\boom2.png");
	Draw::LoadImage(23, L"image\\boom3.png");

	//ゲーム画面背景
	Draw::LoadImage(4, L"image\\Space1.png");
	Draw::LoadImage(24, L"image\\Space2.png");
	Draw::LoadImage(25, L"image\\Space3.png");

	//タイトル
	Draw::LoadImage(26, L"image\\title.png");

	//ゲームクリア
	Draw::LoadImage(27, L"image\\gameclear.png");

	//ゲームオーバー
	Draw::LoadImage(28, L"image\\gameover.png");

	//ゲームセレクト
	Draw::LoadImage(5, L"image\\Select.png");
	Draw::LoadImage(6, L"image\\planet.png");
	Draw::LoadImage(7, L"image\\moon.png");
	Draw::LoadImage(8, L"image\\saturn.png");
	Draw::LoadImage(9, L"image\\Uranus.png");
	
	_endthreadex(0);	//スレッド終了
	return 0;
}

//ミュージック読み込み関数
unsigned __stdcall MusicLoadSled(void *p)
{
	//ミュージック情報取得
	Audio::LoadBackMusic("Select.ogg");
	Audio::LoadSEMusic(0, "Bullet1.ogg");
	//Audio::StartLoopMusic();//バックミュージックスタート
	_endthreadex(0);	//スレッド終了
	return 0;
}

//ゲームメイン関数
unsigned __stdcall GameMainSled(void *p)
{
	while (1)
	{
		//ゲームメイン
		//リスト内のアクション実行
		TaskSystem::ListAction();

		//衝突判定実行
		Collision::CheckStart();

		//レンダリングターゲットセットとレンダリング画面クリア
		float color[] = { 0.0f,0.25f,0.45f,1.0f };
		Dev::GetDeviceContext()->OMSetRenderTargets(1, Dev::GetppRTV(), NULL);//レンダリング先をカラーバッファ(バックバッファ)にセット
		Dev::GetDeviceContext()->ClearRenderTargetView(Dev::GetRTV(), color);//画面をcolorでクリア
		Dev::GetDeviceContext()->RSSetState(Dev::GetRS());//ラスタライズをセット

		//ここからレンダリング開始
		
		TaskSystem::SortPriority();//描画順位変更
		TaskSystem::ListDraw();//リスト内のドロー実行
		Collision::DrawDebug();

		//外部データの読み込み(敵情報)
		unique_ptr<wchar_t> p;	//敵情報ポインター
		int size;				//敵情報の大きさ

		CTitle* title;
		CSelect* select;
		CHero* hero;
		CEnemy* enemy;
		CBackground* background;
		CHeart* heart;

		switch (g_SceneChange)
		{
		case TITLE: //ステージセレクト初期化
			title = new CTitle();
			title->m_priority = 110;
			TaskSystem::InsertObj(title);
			g_SceneChange = TITLE_MAIN;
			break;

		case TITLE_MAIN: //ステージセレクト
			break;

		case STAGESELECT: //ステージセレクト初期化
			select = new CSelect();
			select->m_priority = 100;
			TaskSystem::InsertObj(select);
			g_SceneChange = STAGESELECT_MAIN;
			break;

		case STAGESELECT_MAIN: //ステージセレクト
			break;

		case GAME: //ステージ1初期化
			hero = new CHero();
			hero->m_priority = 90;
			TaskSystem::InsertObj(hero);//宇宙船

			p = Save::ExternalDataOpen(L"Enemy.csv", &size);//外部データ読み込み

			for (int i = 0; i < ENEMY_NUM; ++i)
			{
				enemy = new CEnemy(e_data[i].enemy_type, e_data[i].in_time, e_data[i].x, e_data[i].y,
					e_data[i].enemy_speed, e_data[i].hp, e_data[i].w, e_data[i].h, e_data[i].stop_time,
					e_data[i].out_time, e_data[i].shot_pattern, e_data[i].shot_time, e_data[i].shot_speed, e_data[i].item);
				enemy->m_priority = 90;
				TaskSystem::InsertObj(enemy);//塵

			}

			for (int i = 0; i < heart_num; i++)
			{
				heart = new CHeart(i*60.0f, 5.0f);
				heart->m_priority = 90;
				TaskSystem::InsertObj(heart);
			}
			
			background = new CBackground();
			background->m_priority = 80;
			TaskSystem::InsertObj(background);//背景(ステージ1)

			g_SceneChange = GAME_MAIN;
			break;

		case GAME_MAIN: //ステージ1
			break;
		}

		//レンダリング終了
		Dev::GetSwapChain()->Present(1, 0);//60FPSでバックバッファとプライマリバッファの交換

		//終了
		if (g_ls_game_end==true)
		{
			break;
		}
	}

	_endthreadex(0);	//スレッド終了
	return 0;
}

//Main関数---------------
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{
	//メモリダンプ開始
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	wchar_t name[] = { L"GameEngine" };	//ウィンドウ＆タイトルネーム
	MSG msg;							//メッセージハンドル

	//ウィンドウステータス
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX),CS_HREDRAW | CS_VREDRAW,
		WndProc,0,0,hInstance,NULL,NULL,
		(HBRUSH)(COLOR_WINDOW + 1),NULL,name,NULL
	};

	//ウィンドウクラス作成
	RegisterClassEx(&wcex);

	//ゲーム各システム初期化---
	CWindowCreate::NewWindow(800, 600, name, hInstance);//ウィンドウ作成
	CDeviceCreate::InitDevice(CWindowCreate::GethWnd(), 800, 600);//DirectX Deviceの初期化
	Audio::InitAudio();//オーディオ作成
	Input::InitInput();//入力用のクラス初期化
	Draw::InitPolygonRender();//ポリゴン表示環境の初期化
	TaskSystem::InitTaskSystem();//タスクシステム初期化
	Font::InitFontTex();//フォント初期化
	Collision::InitHitBox();//コリジョンの初期化

	//リソース読み込み-----
	HANDLE handoru[2];
	handoru[0] = (HANDLE)_beginthreadex(NULL, 0, TextureLoadSled, NULL, 0, NULL);	//テクスチャ読み込み
	handoru[1] = (HANDLE)_beginthreadex(NULL, 0, MusicLoadSled, NULL, 0, NULL);		//ミュージック読み込み関数
	WaitForMultipleObjects(2, handoru, TRUE, INFINITE);//読み込みスレッドが終了まで待機
	CloseHandle(handoru[0]);//ハンドル[0]を閉じる
	CloseHandle(handoru[1]);//ハンドル[1]を閉じる

	HANDLE game_handoru;
	game_handoru = (HANDLE)_beginthreadex(NULL, 0, GameMainSled, NULL, 0, NULL);//ゲームメインスレッド実行
	//メッセージループ
	do 
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	} while (msg.message != WM_QUIT);
	WaitForSingleObject(game_handoru, INFINITE);//ゲームメインスレッドが終了待ち
	CloseHandle(game_handoru);//ハンドルを閉じる

	//ゲームシステム破棄
	Collision::DeleteHitBox();//コリジョンの破棄
	Font::DeleteFontTex();//フォントの破棄
	TaskSystem::DeleteTaskSystem();//タスクシステムの破棄
	Draw::DeletePolygonRender();//ポリゴン表示環境の破棄
	CDeviceCreate::ShutDown();//DirectXの環境破棄
	Audio::DeleteAudio();	//オーディオ環境の破棄

	CoUninitialize();

	//この時点で開放されていないメモリの情報の表示
	_CrtDumpMemoryLeaks();
	return true;
}

//コールバック関数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Input::SetMouPos(&uMsg, &lParam);

	switch (uMsg)
	{
		case WM_KEYDOWN:		//ESCキーで終了
			switch (wParam)
			{
			case VK_ESCAPE:
				g_ls_game_end = true;
				PostQuitMessage(0);
				break;
			}
			break;

		case WM_CLOSE:			//ウィンドウを閉じる場合
			g_ls_game_end = true;
			PostQuitMessage(0);

		case WM_DESTROY:		//終了する場合

		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}