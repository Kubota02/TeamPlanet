//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "RankM.h"

extern int total;
extern bool g_key_flag;

CRankM::CRankM()
{
	m_x = 265.0f;
	m_y = 355.0f;

	m_ani_time = 0;

	m_name = RANK;
}

CRankM::~CRankM()
{

}

void CRankM::Action()
{

}

void CRankM::Draw()
{
	if (total >= 1000 && total < 2000)//C
	{
		Draw::Draw2D(46, m_x, m_y);
	}
	else if (total >= 2000 && total < 3500)//B
	{
		Draw::Draw2D(47, m_x, m_y);
	}
	else if (total >= 3500 && total < 5000)//A
	{
		Draw::Draw2D(48, m_x, m_y);
	}
	else if (total >= 5000 && total < 6000)//S
	{
		Draw::Draw2D(49, m_x, m_y);
	}
	else if (total >= 6000)//U
	{
		Draw::Draw2D(50, m_x, m_y);
	}
}