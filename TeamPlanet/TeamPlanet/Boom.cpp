//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Boom.h"

//コンストラクタ
CBoom::CBoom(float x, float y)
{
	m_x = x;
	m_y = y;
}

//デストラクタ
CBoom::~CBoom()
{

}

//アクション
void CBoom::Action()
{

}

//ドロー
void CBoom::Draw()
{
	Draw::Draw2D(21, m_x, m_y);
}