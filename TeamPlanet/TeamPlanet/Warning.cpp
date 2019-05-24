//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Warning.h"

CWarning::CWarning()
{
	//warning1の位置
	m_x1 = 0.0f;
	m_y1 = 0.0f;

	//warning2の位置
	m_x2 = 0.0f;
	m_y2 = 0.0f;

	//出現時間管理用
	m_ani_time = 0;

	m_time = 3;

	m_name = WARNING;
}

CWarning::~CWarning()
{

}

void CWarning::Action()
{
	m_ani_time++;

	if (m_ani_time == 60)
	{
		m_time--;
		m_ani_time = 0;
	}

	if (m_time == 0)
	{
		is_delete = true;
		m_time = 3;
	}
}

void CWarning::Draw()
{
	Draw::Draw2D(51, m_x1, m_y1);
	Draw::Draw2D(52, m_x2, m_y2);
}