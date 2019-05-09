//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameOver.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int h_hp;

CGameOver::CGameOver()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;

	m_ani_time = 0;
}

CGameOver::~CGameOver()
{

}

void CGameOver::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	if (h_hp == 0)
	{
		if (g_key_flag)
		{
			m_ani_time++;
			g_key_flag = false;
		}
	}
	else
	{
		g_key_flag = true;
	}

	if (m_ani_time >= 100)
	{
		Audio::StartLoopMusic(10);//�o�b�N�~���[�W�b�N�X�^�[�g
		Audio::LoopMusicVolume(10, 0.03f);
	}

	if (m_ani_time >= 200)
	{
		if (Input::KeyPush(VK_RETURN))
		{
			Audio::StopLoopMusic(10);
			g_SceneChange = STAGESELECT;
			is_delete = true;
		}
	}
}

void CGameOver::Draw()
{
	if (m_ani_time >= 100)
	{
		//�`��
		Draw::Draw2D(28, m_x, m_y);
	}
}