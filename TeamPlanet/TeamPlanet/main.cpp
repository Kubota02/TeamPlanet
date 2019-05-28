//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�V�X�e���n�̃w�b�_�[�C���N���[�h-----------
#include <stdio.h>
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
#include <process.h>

//Game�V�X�e���p�w�b�_�[(����)�C���N���[�h---
#include "WindowCreate.h"
#include "DeviceCreate.h"
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"
#include "Collision.h"

#include "EnemyData.h"

//�I�u�W�F�N�g�w�b�_---------------
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

//�폜����Ă��Ȃ����������o�͂Ƀ_���v����---
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)

#define new DBG_NEW
#endif
#endif	// _DEBUG

//LIB�̓o�^--------------
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3dCompiler.lib")

//�\����-----------------

//�O���[�o���ϐ�---------
bool g_ls_game_end = false;	//�X���b�h�p�Q�[���I���t���O
int g_SceneChange = TITLE;//�Q�[����ʃt���O
bool g_key_flag = true;//�L�[�t���O
extern ENEMYDATA e_data[ENEMY_NUM];

int heart_num = 5; //�n�[�g�̐�
//int clearpoint;
extern int total;
//int g_time = 60; //�c�莞��

//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//�E�B���h�E�v���W�[�V���[

//�}���`�X���b�h�ɂ���֐�-
//�e�N�X�`���ǂݍ��݊֐�
unsigned __stdcall TextureLoadSled(void *p)
{
	//�C���[�W�ǂݍ���
	//���E��45/60��     8,9�_��
	//��l��
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

	//�G
	Draw::LoadImage(2, L"image\\dust.png");
	Draw::LoadImage(3, L"image\\meteorite1.png");
	Draw::LoadImage(10, L"image\\enemy1.png");
	Draw::LoadImage(11, L"image\\enemy2.png");
	Draw::LoadImage(16, L"image\\satellite.png");
	Draw::LoadImage(17, L"image\\solar.png");
	Draw::LoadImage(18, L"image\\antenna.png");
	Draw::LoadImage(19, L"image\\meteorite2.png");
	Draw::LoadImage(20, L"image\\bulletE.png");

	//�{�[�i�X�G�l�~�[
	Draw::LoadImage(5, L"image\\moon.png");
	Draw::LoadImage(6, L"image\\saturn.png");
	Draw::LoadImage(7, L"image\\Uranus.png");

	//�A�C�e��
	Draw::LoadImage(29, L"image\\defense.png");
	Draw::LoadImage(30, L"image\\speed.png");
	Draw::LoadImage(38, L"image\\lifeup.png");
	Draw::LoadImage(40, L"image\\time.png");

	//�����G�t�F�N�g
	Draw::LoadImage(21, L"image\\boom1.png");
	Draw::LoadImage(22, L"image\\boom2.png");
	Draw::LoadImage(23, L"image\\boom3.png");

	//�Q�[����ʔw�i
	Draw::LoadImage(4, L"image\\Space10.png");
	Draw::LoadImage(24, L"image\\Space20.png");
	Draw::LoadImage(25, L"image\\Space30.png");
	Draw::LoadImage(42, L"image\\Space1.png");
	Draw::LoadImage(43, L"image\\Space2.png");
	Draw::LoadImage(44, L"image\\Space3.png");

	//�^�C�g��
	Draw::LoadImage(26, L"image\\title.png");

	//�Q�[���N���A
	Draw::LoadImage(27, L"image\\gameclear.png");

	//�Q�[���I�[�o�[
	Draw::LoadImage(28, L"image\\gameover.png");

	//�������
	Draw::LoadImage(41, L"image\\description.png");

	//�����N
	Draw::LoadImage(46, L"image\\Crank.png");
	Draw::LoadImage(47, L"image\\Brank.png");
	Draw::LoadImage(48, L"image\\Arank.png");
	Draw::LoadImage(49, L"image\\Srank.png");
	Draw::LoadImage(50, L"image\\Urank.png");

	//warning
	Draw::LoadImage(51, L"image\\warning1.png");//8,9
	Draw::LoadImage(52, L"image\\warning2.png");
	
	_endthreadex(0);	//�X���b�h�I��
	return 0;
}

//�~���[�W�b�N�ǂݍ��݊֐�
unsigned __stdcall MusicLoadSled(void *p)
{
	//�~���[�W�b�N���擾
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
	
	//Audio::StartLoopMusic();//�o�b�N�~���[�W�b�N�X�^�[�g
	_endthreadex(0);	//�X���b�h�I��
	return 0;
}

//�Q�[�����C���֐�
unsigned __stdcall GameMainSled(void *p)
{
	while (1)
	{
		//�Q�[�����C��
		//���X�g���̃A�N�V�������s
		TaskSystem::ListAction();

		//�Փ˔�����s
		Collision::CheckStart();

		//�����_�����O�^�[�Q�b�g�Z�b�g�ƃ����_�����O��ʃN���A
		float color[] = { 0.0f,0.25f,0.45f,1.0f };
		Dev::GetDeviceContext()->OMSetRenderTargets(1, Dev::GetppRTV(), NULL);//�����_�����O����J���[�o�b�t�@(�o�b�N�o�b�t�@)�ɃZ�b�g
		Dev::GetDeviceContext()->ClearRenderTargetView(Dev::GetRTV(), color);//��ʂ�color�ŃN���A
		Dev::GetDeviceContext()->RSSetState(Dev::GetRS());//���X�^���C�Y���Z�b�g

		//�������烌���_�����O�J�n
		
		TaskSystem::SortPriority();//�`�揇�ʕύX
		TaskSystem::ListDraw();//���X�g���̃h���[���s
		Collision::DrawDebug();

		//�O���f�[�^�̓ǂݍ���(�G���)
		unique_ptr<wchar_t> p;	//�G���|�C���^�[
		int size;				//�G���̑傫��

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
		case TITLE: //�X�e�[�W�Z���N�g������
			title = new CTitle();
			title->m_priority = 110;
			TaskSystem::InsertObj(title);
			g_SceneChange = TITLE_MAIN;
			break;

		case TITLE_MAIN: //�X�e�[�W�Z���N�g
			break;

		case DESCRIPTION: //�������������
			description = new CDescription();
			description->m_priority = 100;
			TaskSystem::InsertObj(description);
			g_SceneChange = DESCRIPTION_MAIN;
			break;

		case DESCRIPTION_MAIN: //�������
			break;

		case GAME: //�X�e�[�W1������
			heart_num = 5;
			total = 0;
			//clearpoint = 1000;

			//�I�[�f�B�I�A�A�A�����Ă킩���Ǝv����������
			Audio::StartLoopMusic(7);
			Audio::LoopMusicVolume(7, 0.03f);

			hero = new CHero();
			hero->m_priority = 80;
			TaskSystem::InsertObj(hero);//�F���D

			p = Save::ExternalDataOpen(L"Enemy.csv", &size);//�O���f�[�^�ǂݍ���

			for (int i = 0; i < ENEMY_NUM; ++i)
			{
				enemy = new CEnemy(e_data[i].enemy_type, e_data[i].in_time, e_data[i].x, e_data[i].y,
					e_data[i].enemy_speed, e_data[i].hp, e_data[i].w, e_data[i].h, e_data[i].stop_time,
					e_data[i].out_time, e_data[i].shot_pattern, e_data[i].shot_time, e_data[i].shot_speed,
					e_data[i].item, e_data[i].point);
				enemy->m_priority = 80;
				TaskSystem::InsertObj(enemy);//�o

			}

			heart = new CHeart();
			heart->m_priority = 80;
			TaskSystem::InsertObj(heart);//�n�[�g

			time = new CTime();
			time->m_priority = 80;
			TaskSystem::InsertObj(time);//�^�C��

			gauge = new CGauge();
			gauge->m_priority = 60;
			TaskSystem::InsertObj(gauge);//�Q�[�W
			
			background = new CBackground();
			background->m_priority = 60;
			TaskSystem::InsertObj(background);//�w�i(�X�e�[�W1)

			back = new CBack();
			back->m_priority = 50;
			TaskSystem::InsertObj(back);//�w�i�̔w�i(�X�e�[�W1)

			/*rankm = new CRankM();
			rankm->m_priority = 60;
			TaskSystem::InsertObj(rankm);*/

			

			g_SceneChange = GAME_MAIN;
			break;

		case GAME_MAIN: //�X�e�[�W1
			break;

		case GAMEOVER: //�Q�[���I�[�o�[������
			gameover = new CGameOver();
			gameover->m_priority = 70;
			TaskSystem::InsertObj(gameover);
			g_SceneChange = GAMEOVER_MAIN;
			Audio::StopLoopMusic(7);
			break;

		case GAMEOVER_MAIN: //�Q�[���I�[�o�[
			break;

		case GAMECLEAR: //�Q�[���N���A������
			gameclear = new CGameClear();
			gameclear->m_priority = 70;
			TaskSystem::InsertObj(gameclear);

			rankm = new CRankM();
			rankm->m_priority = 70;
			TaskSystem::InsertObj(rankm);

			g_SceneChange = GAMECLEAR_MAIN;

			break;

		case GAMECLEAR_MAIN: //�Q�[���N���A
			break;

		case ALLCLEAR: //�Q�[���N���A������
			g_SceneChange = ALLCLEAR_MAIN;
			break;

		case ALLCLEAR_MAIN: //�Q�[���N���A
			break;
		}

		//�����_�����O�I��
		Dev::GetSwapChain()->Present(1, 0);//60FPS�Ńo�b�N�o�b�t�@�ƃv���C�}���o�b�t�@�̌���

		//�I��
		if (g_ls_game_end==true)
		{
			break;
		}
	}

	_endthreadex(0);	//�X���b�h�I��
	return 0;
}

//Main�֐�---------------
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{
	//�������_���v�J�n
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	wchar_t name[] = { L"GameEngine" };	//�E�B���h�E���^�C�g���l�[��
	MSG msg;							//���b�Z�[�W�n���h��

	//�E�B���h�E�X�e�[�^�X
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX),CS_HREDRAW | CS_VREDRAW,
		WndProc,0,0,hInstance,NULL,NULL,
		(HBRUSH)(COLOR_WINDOW + 1),NULL,name,NULL
	};

	//�E�B���h�E�N���X�쐬
	RegisterClassEx(&wcex);

	//�Q�[���e�V�X�e��������---
	CWindowCreate::NewWindow(800, 600, name, hInstance);//�E�B���h�E�쐬
	CDeviceCreate::InitDevice(CWindowCreate::GethWnd(), 800, 600);//DirectX Device�̏�����
	Audio::InitAudio();//�I�[�f�B�I�쐬
	Input::InitInput();//���͗p�̃N���X������
	Draw::InitPolygonRender();//�|���S���\�����̏�����
	TaskSystem::InitTaskSystem();//�^�X�N�V�X�e��������
	Font::InitFontTex();//�t�H���g������
	Collision::InitHitBox();//�R���W�����̏�����

	//���\�[�X�ǂݍ���-----
	HANDLE handoru[2];
	handoru[0] = (HANDLE)_beginthreadex(NULL, 0, TextureLoadSled, NULL, 0, NULL);	//�e�N�X�`���ǂݍ���
	handoru[1] = (HANDLE)_beginthreadex(NULL, 0, MusicLoadSled, NULL, 0, NULL);		//�~���[�W�b�N�ǂݍ��݊֐�
	WaitForMultipleObjects(2, handoru, TRUE, INFINITE);//�ǂݍ��݃X���b�h���I���܂őҋ@
	CloseHandle(handoru[0]);//�n���h��[0]�����
	CloseHandle(handoru[1]);//�n���h��[1]�����

	HANDLE game_handoru;
	game_handoru = (HANDLE)_beginthreadex(NULL, 0, GameMainSled, NULL, 0, NULL);//�Q�[�����C���X���b�h���s
	//���b�Z�[�W���[�v
	do 
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	} while (msg.message != WM_QUIT);
	WaitForSingleObject(game_handoru, INFINITE);//�Q�[�����C���X���b�h���I���҂�
	CloseHandle(game_handoru);//�n���h�������

	//�Q�[���V�X�e���j��
	Collision::DeleteHitBox();//�R���W�����̔j��
	Font::DeleteFontTex();//�t�H���g�̔j��
	TaskSystem::DeleteTaskSystem();//�^�X�N�V�X�e���̔j��
	Draw::DeletePolygonRender();//�|���S���\�����̔j��
	CDeviceCreate::ShutDown();//DirectX�̊��j��
	Audio::DeleteAudio();	//�I�[�f�B�I���̔j��

	CoUninitialize();

	//���̎��_�ŊJ������Ă��Ȃ��������̏��̕\��
	_CrtDumpMemoryLeaks();
	return true;
}

//�R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Input::SetMouPos(&uMsg, &lParam);

	switch (uMsg)
	{
		case WM_KEYDOWN:		//ESC�L�[�ŏI��
			switch (wParam)
			{
			case VK_ESCAPE:
				g_ls_game_end = true;
				PostQuitMessage(0);
				break;
			}
			break;

		case WM_CLOSE:			//�E�B���h�E�����ꍇ
			g_ls_game_end = true;
			PostQuitMessage(0);

		case WM_DESTROY:		//�I������ꍇ

		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}