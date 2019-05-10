//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Defense.h"

CDefense::CDefense(float x,float y)
{
	m_x = x;
	m_y = y;
}

CDefense::~CDefense()
{

}

void CDefense::Action()
{

}

void CDefense::Draw()
{
	
}