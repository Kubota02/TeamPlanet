//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameOver.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int h_hp;
extern int total;

CGameOver::CGameOver()
{
	//背景の初期位置
	m_x = 0.0f;
	m_y = 0.0f;

	key_flag = true;
	rank_key_flag = true;

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
		if (key_flag)
		{
			m_ani_time++;
			key_flag = false;
		}
	}
	else
	{
		key_flag = true;
	}

	if (0 <= total && total < 1000)
	{
		if (rank_key_flag)
		{
			m_ani_time++;
			rank_key_flag = false;
		}
	}
	else
	{
		rank_key_flag = true;
	}

	if (m_ani_time >= 100)
	{
		Audio::StartLoopMusic(10);//バックミュージックスタート
		Audio::LoopMusicVolume(10, 0.03f);
	}

	if (m_ani_time >= 240)
	{
		if (Input::KeyPush(VK_RETURN))
		{
			if (g_key_flag)
			{
				Audio::StopLoopMusic(10);
				g_SceneChange = TITLE;
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
}

void CGameOver::Draw()
{
	if (m_ani_time >= 100)
	{
		//描画
		Draw::Draw2D(28, m_x, m_y);
	}
}