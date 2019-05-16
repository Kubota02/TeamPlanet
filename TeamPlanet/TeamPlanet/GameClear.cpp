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

	//�F���D�̏����ʒu
	m_x2 = -120.0f;
	m_y2 = 430.0f;

	//�ړ��x�N�g���̏�����
	m_vx = 7.0f;

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

	if (total >= 50)
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
		m_x2 += m_vx;
	}

	if (m_ani_time >= 200)
	{
		if (Input::KeyPush(VK_RETURN))
		{
			g_SceneChange = STAGESELECT;
			is_delete = true;
		}
	}
}

void CGameClear::Draw()
{
	//�`��
	if (m_ani_time >= 100)
	{
		Draw::Draw2D(27, m_x, m_y);
		Draw::Draw2D(14, m_x2, m_y2);
	}
}