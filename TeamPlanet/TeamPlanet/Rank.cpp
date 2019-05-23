//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Rank.h"

extern int g_SceneChange;
extern int total;

CRank::CRank()
{
	m_x = 250.0f;
	m_y = 350.0f;
}

CRank::~CRank()
{

}

void CRank::Action()
{

}

void CRank::Draw()
{
	if (total == 50)
	{
		Draw::Draw2D(45, m_x, m_y);
	}
}