//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Heart.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CHeart::CHeart(float x, float y)
{
	m_x = x;
	m_y = y;
}

//デストラクタ
CHeart::~CHeart()
{

}

//アクション
void CHeart::Action()
{

}

//ドロー
void CHeart::Draw()
{
	Draw::Draw2D(15, m_x, m_y);
}