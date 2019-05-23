//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "RankM.h"

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
	Draw::Draw2D(46, m_x, m_y);
}