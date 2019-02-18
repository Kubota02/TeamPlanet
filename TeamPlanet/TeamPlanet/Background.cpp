//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"

CBackground::CBackground()
{
	//背景の初期位置
	m_x = 0.0f;
	m_y = 0.0f;

	//初期移動方向
	m_vx = 0.0f;
}

CBackground::~CBackground()
{

}

void CBackground::Action()
{
	
}

void CBackground::Draw()
{
	//描画
	Draw::Draw2D(4, m_x, m_y);
}