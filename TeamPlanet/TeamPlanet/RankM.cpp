//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "RankM.h"

extern int total;

CRankM::CRankM()
{
	m_x = 265.0f;
	m_y = 275.0f;
}

CRankM::~CRankM()
{

}

void CRankM::Action()
{

}

void CRankM::Draw()
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
		//Draw::Draw2D(50, m_x, m_y);
	}
	/*Draw::Draw2D(46, m_x, m_y);*/
}