//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Description.h"

extern int g_SceneChange;
extern bool g_key_flag;

CDescription::CDescription()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;

	m_ani_time = 0;
	m_time = 0;
}

CDescription::~CDescription()
{

}

void CDescription::Action()
{
	m_time++;
	Audio::StartLoopMusic(12);//�o�b�N�~���[�W�b�N�X�^�[�g
	Audio::LoopMusicVolume(12, 0.03f);

	if (m_time >= 180)
	{
		if (Input::KeyPush(VK_RETURN))
		{
			Audio::StartMusic(6);
			Audio::StopLoopMusic(12);
			g_SceneChange = GAME;
			is_delete = true;
		}
		else
		{
			g_key_flag = true;
		}
	}
}

void CDescription::Draw()
{
	//�`��
	Draw::Draw2D(41, m_x, m_y);
}