//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Heart.h"

extern int heart_num;

//コンストラクタ
CHeart::CHeart()
{
	
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
	//Draw::Draw2D(15, m_x, m_y);
	for (int i = 0; i < heart_num; i++)
	{
		Draw::Draw2D(15, i*60.0f, 5.0f);
	}
}