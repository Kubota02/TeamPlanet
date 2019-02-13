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

//�I�u�W�F�N�g�w�b�_---------------
#include "Hero.h"
#include "Bullet.h"
#include "Dust.h"
#include "Meteorite.h"

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

//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//�E�B���h�E�v���W�[�V���[

//�}���`�X���b�h�ɂ���֐�-
//�e�N�X�`���ǂݍ��݊֐�
unsigned __stdcall TextureLoadSled(void *p)
{
	//�C���[�W�ǂݍ���
	Draw::LoadImage(0, L"image\\Space ship.png");
	Draw::LoadImage(1, L"image\\bullet.png");
	Draw::LoadImage(2, L"image\\dust.png");
	Draw::LoadImage(3, L"image\\meteorite.png");
	_endthreadex(0);	//�X���b�h�I��
	return 0;
}

//�~���[�W�b�N�ǂݍ��݊֐�
unsigned __stdcall MusicLoadSled(void *p)
{
	//�~���[�W�b�N���擾
	//Audio::LoadBackMusic("Test.ogg");
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

		//���X�g���̃h���[���s
		TaskSystem::ListDraw();
		Collision::DrawDebug();

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

	//�I�u�W�F�N�g�쐬
	CHero* hero = new CHero();
	hero->m_priority = 90;
	TaskSystem::InsertObj(hero);

	CDust* dust = new CDust();
	dust->m_priority = 90;
	TaskSystem::InsertObj(dust);

	CMeteorite* meteorite = new CMeteorite();
	meteorite->m_priority = 90;
	TaskSystem::InsertObj(meteorite);

	TaskSystem::SortPriority();//�`�揇�ʕύX

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