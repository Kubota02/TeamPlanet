//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Select.h"

extern int g_SceneChange;
extern bool g_key_flag;

CSelect::CSelect()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;

	m_cursor = STAGE1;
	m_ani_time = 0;
	key_flag = true;
}

CSelect::~CSelect()
{

}

void CSelect::Action()
{
	//�����������獶��
	if (Input::KeyPush(VK_LEFT) == true)
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
	//�E����������E��
	else if (Input::KeyPush(VK_RIGHT) == true)
	{
		if (key_flag)
		{
			if (m_cursor < 2)
			{
				m_cursor++;
				key_flag = false;
			}
		}
	}
	else key_flag = true;

	if (Input::KeyPush(VK_RETURN) == true)
	{
		if (g_key_flag)
		{
			g_key_flag = false;
		}
	}
	else
	{
		g_key_flag = true;
	}
	
	//�J�[�\���ʒu�����Ȃ�
	if (m_cursor == LEFT)
	{
		g_SceneChange = GAME;
		//is_delete = true;
	}
	//�J�[�\���ʒu���E�Ȃ�
	else if (m_cursor == RIGHT)
	{
		//g_SceneNumber = GAME;
		//is_delete = true;
	}
	//�J�[�\���ʒu�����Ȃ�
	else if (m_cursor == UNDER)
	{
		//g_SceneNumber = GAME;
		//is_delete = true;
	}
}

void CSelect::Draw()
{
	//�`��
	Draw::Draw2D(5, m_x, m_y);

	if (m_cursor == LEFT)
	{
		Draw::Draw2D(7, 0, 0);
	}
	else if (m_cursor == RIGHT)
	{
		Draw::Draw2D(8, 0, 0);
	}
	else if (m_cursor == UNDER)
	{
		Draw::Draw2D(9, 0, 0);
	}
}