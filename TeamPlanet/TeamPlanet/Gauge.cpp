//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Gauge.h"

extern int g_SceneChange;

//コンストラクタ
CGauge::CGauge()
{
	m_x = 450.0f;
	m_y = 15.0f;
}

//デストラクタ
CGauge::~CGauge()
{

}

//アクション
void CGauge::Action()
{

}

//ドロー
void CGauge::Draw()
{
	Draw::Draw2D(34, m_x, m_y);
}