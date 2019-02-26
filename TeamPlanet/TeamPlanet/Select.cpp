//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Select.h"

extern int g_SceneChange;
extern bool g_key_flag;

CSelect::CSelect()
{
	//背景の初期位置
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
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	//左を押したら左に
	if (Input::KeyPush(VK_LEFT))
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
	//右を押したら右に
	else if (Input::KeyPush(VK_RIGHT))
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
	
	//カーソル位置が左なら
	if (m_cursor == LEFT)
	{
		if (m_ani_time == 25)
		{
			g_SceneChange = GAME;
			is_delete = true;
		}
	}
	//カーソル位置が中央なら
	else if (m_cursor == RIGHT)
	{
		if (m_ani_time == 25)
		{
			g_SceneChange = GAME;
			is_delete = true;
		}
	}
	//カーソル位置が右なら
	else if (m_cursor == UNDER)
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
	//描画
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