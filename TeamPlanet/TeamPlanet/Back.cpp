//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Back.h"

CBack::CBack()
{
	//背景の初期位置
	m_x = 0.0f;
	m_y = 0.0f;
}

CBack::~CBack()
{

}

void CBack::Action()
{

}

void CBack::Draw()
{
	//描画
	Draw::Draw2D(42, m_x, m_y);
}