//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Back.h"

CBack::CBack()
{
	//背景の初期位置
	m_x1 = 0.0f;
	m_x2 = 1000.0f;
	m_y = 0.0f;
}

CBack::~CBack()
{

}

void CBack::Action()
{
	//背景1
	m_x1 -= 0.6f;
	if (m_x1 < -990.0f)
	{
		m_x1 = 980.0f;
	}

	//背景2
	m_x2 -= 0.6f;
	if (m_x2 < -990.0f)
	{
		m_x2 = 980.0f;
	}
}

void CBack::Draw()
{
	//描画
	Draw::Draw2D(42, m_x1, m_y);
	Draw::Draw2D(42, m_x2, m_y);
}