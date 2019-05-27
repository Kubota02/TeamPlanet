//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "RankM.h"

extern int total;
extern bool g_key_flag;

CRankM::CRankM()
{
	m_x = 265.0f;
	m_y = 275.0f;

	m_ani_time = 0;
}

CRankM::~CRankM()
{

}

void CRankM::Action()
{
	if (m_ani_time != 0)
	{

		m_ani_time++;
	}

	if (total >= 1000)
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

	g_key_flag = true;
}

void CRankM::Draw()
{
	if (m_ani_time >= 100)
	{
		if (total >= 200 && total < 400)
		{
			Draw::Draw2D(46, m_x, m_y);
		}
		else if (total >= 400 && total < 600)
		{
			Draw::Draw2D(47, m_x, m_y);
		}
		else if (total >= 600 && total < 800)
		{
			Draw::Draw2D(48, m_x, m_y);
		}
		else if (total >= 800 && total < 1000)
		{
			Draw::Draw2D(49, m_x, m_y);
		}
		else if (total >= 1000)
		{
			Draw::Draw2D(50, m_x, m_y);
		}
	}
	/*if (total >= 200 && total < 400)
	{
		Draw::Draw2D(46, m_x, m_y);
	}
	else if (total >= 400 && total < 600)
	{
		Draw::Draw2D(47, m_x, m_y);
	}
	else if (total >= 600 && total < 800)
	{
		Draw::Draw2D(48, m_x, m_y);
	}
	else if (total >= 800 && total < 1000)
	{
		Draw::Draw2D(49, m_x, m_y);
	}
	else if (total >= 1000)
	{
		Draw::Draw2D(50, m_x, m_y);
	}*/

	/*Draw::Draw2D(46, m_x, m_y);*/
}