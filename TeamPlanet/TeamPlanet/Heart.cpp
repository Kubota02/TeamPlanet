//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Heart.h"

extern int heart_num;
extern int total;

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
	//得点が目標得点に到達したら自身を削除
	if (total >= 1000)
	{
		is_delete = true;
	}
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