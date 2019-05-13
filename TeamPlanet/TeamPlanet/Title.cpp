//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Title.h"

extern int g_SceneChange;
extern bool g_key_flag;

CTitle::CTitle()
{
	//背景の初期位置
	m_x = 0.0f;
	m_y = 0.0f;

	//宇宙船の初期位置
	m_x2 = 90.0f;
	m_y2 = 430.0f;

	m_ani_time = 0;

	m_vx = 7.0f;
}

CTitle::~CTitle()
{

}

void CTitle::Action()
{
	Audio::StartLoopMusic(8);//バックミュージックスタート
	Audio::LoopMusicVolume(8, 0.03f);

	if (m_ani_time != 0)
	{
		
		m_ani_time++;
		m_x2 += m_vx;
	}

	if (Input::KeyPush(VK_RETURN))
	{
		Audio::StartMusic(9);
		Audio::SEMusicVolume(9, 0.2f);

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
		
		Audio::StopLoopMusic(8);
		g_SceneChange = STAGESELECT;
		is_delete = true;
	}
}

void CTitle::Draw()
{
	//描画
	Draw::Draw2D(26, m_x, m_y);

	if (m_ani_time <= 1)
	{
		Draw::Draw2D(0, m_x2, m_y2);
	}
	else
	{
		Draw::Draw2D(14, m_x2-70, m_y2);
	}
}