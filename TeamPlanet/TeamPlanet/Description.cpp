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
}

CDescription::~CDescription()
{

}

void CDescription::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	if (Input::KeyPush(VK_RETURN))
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

	if (m_ani_time == 100)
	{
		g_SceneChange = STAGESELECT;
		is_delete = true;
	}
}

void CDescription::Draw()
{
	//�`��
	Draw::Draw2D(41, m_x, m_y);
}