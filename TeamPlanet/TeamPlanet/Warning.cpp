//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Warning.h"

CWarning::CWarning()
{
	//
	m_x1 = 100.0f;
	m_y1 = 100.0f;

	//
	m_x2 = 100.0f;
	m_y2 = 100.0f;
}

CWarning::~CWarning()
{

}

void CWarning::Action()
{

}

void CWarning::Draw()
{
	Draw::Draw2D(51, m_x1, m_y1);
	Draw::Draw2D(52, m_x2, m_y2);
}