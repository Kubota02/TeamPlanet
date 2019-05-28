//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameClear.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int total;

CGameClear::CGameClear()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;

	m_ani_time = 0;
}

CGameClear::~CGameClear()
{

}

void CGameClear::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	if (total >= 1000)
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
		Audio::StartLoopMusic(11);//�o�b�N�~���[�W�b�N�X�^�[�g
		Audio::LoopMusicVolume(11, 0.03f);
	}

	if (m_ani_time >= 240)
	{
		if (Input::KeyPush(VK_RETURN))
		{
			if (g_key_flag)
			{
				total = 0;
				Audio::StopLoopMusic(11);
				g_SceneChange = TITLE;
				g_key_flag = false;
				is_delete = true;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
}

void CGameClear::Draw()
{
	//�`��
	if (m_ani_time >= 100)
	{
		Draw::Draw2D(27, m_x, m_y);
	}
}