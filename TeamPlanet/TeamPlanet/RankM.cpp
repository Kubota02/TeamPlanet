//STL�f�o�b�N�@�\��OFF�ɂ���
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
	//C�����N
	if (total >= 1500 && total < 2300)
	{
		Draw::Draw2D(46, m_x, m_y);
	}
	//B�����N
	else if (total >= 2300 && total < 3300)
	{
		Draw::Draw2D(47, m_x, m_y);
	}
	//A�����N
	else if (total >= 3300 && total < 4600)
	{
		Draw::Draw2D(48, m_x, m_y);
	}
	//S�����N
	else if (total >= 4600 && total < 6400)
	{
		Draw::Draw2D(49, m_x, m_y);
	}
	//U�����N
	else if (total >= 6400)
	{
		Draw::Draw2D(50, m_x, m_y);
	}
}