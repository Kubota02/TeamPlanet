//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "BossBoom.h"

extern int e_hp;
extern int g_SceneChange;
extern int enemy;

//コンストラクタ
CBossBoom::CBossBoom(float x, float y)
{
	m_x = x;
	m_y = y;

	m_ani_time = 0;

	boom_flag = true;
}

//デストラクタ
CBossBoom::~CBossBoom()
{

}

//アクション
void CBossBoom::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	if (e_hp == 0)
	{
		if (boom_flag)
		{
			m_ani_time++;
			boom_flag = false;
		}
	}
	else
	{
		boom_flag = true;
	}

	if (m_ani_time >= 120)
	{
		is_delete = true;
		m_ani_time = 0;
	}
}

//ドロー
void CBossBoom::Draw()
{
	Draw::Draw2D(22, m_x, m_y);
}