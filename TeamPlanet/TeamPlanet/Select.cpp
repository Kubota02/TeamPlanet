//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Select.h"

extern int g_SceneChange;
//extern bool g_key_flag;

CSelect::CSelect()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;
}

CSelect::~CSelect()
{

}

void CSelect::Action()
{
	//�����������獶��
	if (Input::KeyPush(VK_LEFT) == true ||
		Input::KeyPush(VK_UP) == true)
	{
		if (key_flag)
		{

			if (m_cursor > 0)
			{
				m_cursor--;
				key_flag = false;
			}
		}
	}

	if (m_cursor == LEFT)
	{
		if (m_ani_time == 25)
		{
			g_SceneChange = GAME;
			is_delete = true;
		}
	}
}

void CSelect::Draw()
{
	//�`��
	Draw::Draw2D(5, m_x, m_y);

	if (m_cursor == LEFT)
	{
		if (m_ani_time)
		{
			Draw::Draw2D(6, 100, 100);
		}
		else
		{
			Draw::Draw2D(5, 100, 100);
		}
	}
}