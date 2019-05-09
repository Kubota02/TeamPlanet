//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameOver.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int h_hp;

CGameOver::CGameOver()
{
	//背景の初期位置
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
		Audio::StartLoopMusic(10);//バックミュージックスタート
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
		//描画
		Draw::Draw2D(28, m_x, m_y);
	}
}