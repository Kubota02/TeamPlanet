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
#include "Time.h"
#include "Title.h"
#include "GameOver.h"
#include "GameClear.h"
#include "Gauge.h"
#include "Description.h"
#include "Back.h"
#include "RankM.h"
#include "Warning.h"

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
int g_SceneChange = TITLE;//ゲーム画面フラグ
bool g_key_flag = true;//キーフラグ
extern ENEMYDATA e_data[ENEMY_NUM];

int heart_num = 5; //ハートの数
//int clearpoint;
extern int total;
//int g_time = 60; //残り時間

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//ウィンドウプロジーシャー

//マルチスレッドにする関数-
//テクスチャ読み込み関数
unsigned __stdcall TextureLoadSled(void *p)
{
	//イメージ読み込み
	//限界＜45/60＞     8,9ダメ
	//主人公
	Draw::LoadImage(0, L"image\\Space ship.png");
	Draw::LoadImage(1, L"image\\bullet1.png");
	Draw::LoadImage(32, L"image\\bullet2.png");
	Draw::LoadImage(12, L"image\\Space ship 1.png");
	Draw::LoadImage(13, L"image\\Space ship 2.png");
	Draw::LoadImage(14, L"image\\Space ship fire.png");
	Draw::LoadImage(15, L"image\\life.png");
	Draw::LoadImage(31, L"image\\meter.png");
	Draw::LoadImage(34, L"image\\meter1.png");
	Draw::LoadImage(39, L"image\\stopwatch.png");

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

	//ボーナスエネミー
	Draw::LoadImage(5, L"image\\moon.png");
	Draw::LoadImage(6, L"image\\saturn.png");
	Draw::LoadImage(7, L"image\\Uranus.png");

	//アイテム
	Draw::LoadImage(29, L"image\\defense.png");
	Draw::LoadImage(30, L"image\\speed.png");
	Draw::LoadImage(38, L"image\\lifeup.png");
	Draw::LoadImage(40, L"image\\time.png");

	//爆発エフェクト
	Draw::LoadImage(21, L"image\\boom1.png");
	Draw::LoadImage(22, L"image\\boom2.png");
	Draw::LoadImage(23, L"image\\boom3.png");

	//ゲーム画面背景
	Draw::LoadImage(4, L"image\\Space10.png");
	Draw::LoadImage(24, L"image\\Space20.png");
	Draw::LoadImage(25, L"image\\Space30.png");
	Draw::LoadImage(42, L"image\\Space1.png");
	Draw::LoadImage(43, L"image\\Space2.png");
	Draw::LoadImage(44, L"image\\Space3.png");

	//タイトル
	Draw::LoadImage(26, L"image\\title.png");

	//ゲームクリア
	Draw::LoadImage(27, L"image\\gameclear.png");

	//ゲームオーバー
	Draw::LoadImage(28, L"image\\gameover.png");

	//操作説明
	Draw::LoadImage(41, L"image\\description.png");

	//ランク
	Draw::LoadImage(46, L"image\\Crank.png");
	Draw::LoadImage(47, L"image\\Brank.png");
	Draw::LoadImage(48, L"image\\Arank.png");
	Draw::LoadImage(49, L"image\\Srank.png");
	Draw::LoadImage(50, L"image\\Urank.png");

	//warning
	Draw::LoadImage(51, L"image\\warning1.png");//8,9
	Draw::LoadImage(52, L"image\\warning2.png");
	
	_endthreadex(0);	//スレッド終了
	return 0;
}

//ミュージック読み込み関数
unsigned __stdcall MusicLoadSled(void *p)
{
	//ミュージック情報取得
	Audio::LoadSEMusic(0, "Bullet1.ogg");
	Audio::LoadSEMusic(1, "Bullet2.ogg");
	Audio::LoadSEMusic(2, "boom1.ogg");
	Audio::LoadSEMusic(3, "boom3.ogg");
	Audio::LoadSEMusic(5, "selectButton.ogg");
	Audio::LoadSEMusic(6, "selectE.ogg");
	Audio::LoadBackMusic(7, "moon.ogg");
	Audio::LoadBackMusic(8, "Title.ogg");
	Audio::LoadSEMusic(9, "Fire.ogg");
	Audio::LoadBackMusic(10, "gameover.ogg");
	Audio::LoadBackMusic(11, "gameclear.ogg");
	Audio::LoadBackMusic(12, "Sethumei.ogg");
	Audio::LoadSEMusic(13, "speed.ogg");
	Audio::LoadSEMusic(14, "defense.ogg");
	Audio::LoadSEMusic(15, "heart.ogg");
	Audio::LoadBackMusic(16, "warning.ogg");
	
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
		CHero* hero;
		CEnemy* enemy;
		CBackground* background;
		CHeart* heart;
		CGameOver* gameover;
		CGameClear* gameclear;
		CTime* time;
		CGauge* gauge;
		CDescription* description;
		CBack* back;
		CRankM* rankm;
		CWarning* warning;

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

		case DESCRIPTION: //操作説明初期化
			description = new CDescription();
			description->m_priority = 100;
			TaskSystem::InsertObj(description);
			g_SceneChange = DESCRIPTION_MAIN;
			break;

		case DESCRIPTION_MAIN: //操作説明
			break;

		case GAME: //ステージ1初期化
			heart_num = 5;
			total = 0;
			//clearpoint = 1000;

			//オーディオ、、、だってわからんと思ったんやもん
			Audio::StartLoopMusic(7);
			Audio::LoopMusicVolume(7, 0.03f);

			hero = new CHero();
			hero->m_priority = 80;
			TaskSystem::InsertObj(hero);//宇宙船

			p = Save::ExternalDataOpen(L"Enemy.csv", &size);//外部データ読み込み

			for (int i = 0; i < ENEMY_NUM; ++i)
			{
				enemy = new CEnemy(e_data[i].enemy_type, e_data[i].in_time, e_data[i].x, e_data[i].y,
					e_data[i].enemy_speed, e_data[i].hp, e_data[i].w, e_data[i].h, e_data[i].stop_time,
					e_data[i].out_time, e_data[i].shot_pattern, e_data[i].shot_time, e_data[i].shot_speed,
					e_data[i].item, e_data[i].point);
				enemy->m_priority = 80;
				TaskSystem::InsertObj(enemy);//塵

			}

			heart = new CHeart();
			heart->m_priority = 80;
			TaskSystem::InsertObj(heart);//ハート

			time = new CTime();
			time->m_priority = 80;
			TaskSystem::InsertObj(time);//タイム

			gauge = new CGauge();
			gauge->m_priority = 60;
			TaskSystem::InsertObj(gauge);//ゲージ
			
			background = new CBackground();
			background->m_priority = 60;
			TaskSystem::InsertObj(background);//背景(ステージ1)

			back = new CBack();
			back->m_priority = 50;
			TaskSystem::InsertObj(back);//背景の背景(ステージ1)

			/*rankm = new CRankM();
			rankm->m_priority = 60;
			TaskSystem::InsertObj(rankm);*/

			

			g_SceneChange = GAME_MAIN;
			break;

		case GAME_MAIN: //ステージ1
			break;

		case GAMEOVER: //ゲームオーバー初期化
			gameover = new CGameOver();
			gameover->m_priority = 70;
			TaskSystem::InsertObj(gameover);
			g_SceneChange = GAMEOVER_MAIN;
			Audio::StopLoopMusic(7);
			break;

		case GAMEOVER_MAIN: //ゲームオーバー
			break;

		case GAMECLEAR: //ゲームクリア初期化
			gameclear = new CGameClear();
			gameclear->m_priority = 70;
			TaskSystem::InsertObj(gameclear);

			rankm = new CRankM();
			rankm->m_priority = 70;
			TaskSystem::InsertObj(rankm);

			g_SceneChange = GAMECLEAR_MAIN;

			break;

		case GAMECLEAR_MAIN: //ゲームクリア
			break;

		case ALLCLEAR: //ゲームクリア初期化
			g_SceneChange = ALLCLEAR_MAIN;
			break;

		case ALLCLEAR_MAIN: //ゲームクリア
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