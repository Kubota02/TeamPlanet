//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameOver.h"

extern int g_SceneChange;
extern bool g_key_flag;

CGameOver::CGameOver()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;
}

CGameOver::~CGameOver()
{

}

void CGameOver::Action()
{
	//Audio::StartLoopMusic(10);//�o�b�N�~���[�W�b�N�X�^�[�g
	//Audio::LoopMusicVolume(10, 0.03f);
}

void CGameOver::Draw()
{
	//�`��
	Draw::Draw2D(28, m_x, m_y);
}