//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "HeroBoom.h"

extern bool g_key_flag;
extern int h_hp;
extern int g_SceneChange;

//コンストラクタ
CHeroBoom::CHeroBoom(float x, float y)
{
	m_x = x;
	m_y = y;

	m_ani_time = 0;
}

//デストラクタ
CHeroBoom::~CHeroBoom()
{

}

//アクション
void CHeroBoom::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	//主人公のHPが0になったとき
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
	
	if (m_ani_time >= 80)
	{
		is_delete = true;
		g_SceneChange = GAMEOVER;
	}
}

//ドロー
void CHeroBoom::Draw()
{
	//描画
	Draw::Draw2D(21, m_x, m_y);
}