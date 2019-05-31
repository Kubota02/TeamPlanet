//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "EnemyBoom.h"

extern int e_hp;
extern int g_SceneChange;
extern int enemy;

//コンストラクタ
CEnemyBoom::CEnemyBoom(float x, float y)
{
	m_x = x;
	m_y = y;

	m_ani_time = 0;

	boom_flag == true;
}

//デストラクタ
CEnemyBoom::~CEnemyBoom()
{

}

//アクション
void CEnemyBoom::Action()
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

	if (m_ani_time >= 30)
	{
		is_delete = true;
		m_ani_time = 0;
	}
}

//ドロー
void CEnemyBoom::Draw()
{
	Draw::Draw2D(23, m_x, m_y);
}