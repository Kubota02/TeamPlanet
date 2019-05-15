//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Gauge.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;

//コンストラクタ
CGauge::CGauge()
{
	//ゲージ
	m_x = 480.0f;
	m_y = 20.0f;

	//メーター
	m_x2 = 480.0f;
	m_y2 = 20.0f;

	//アニメーション
	m_ani_time = 0;
}

//デストラクタ
CGauge::~CGauge()
{

}

//アクション
void CGauge::Action()
{
	m_ani_time = total;

	//ハートが無くなった時に自身を削除
	if (heart_num <= 0)
	{
		is_delete = true;
	}

	//得点が目標得点に到達したら自身を削除
	if (total >= 50)
	{
		is_delete = true;
	}
}

//ドロー
void CGauge::Draw()
{
	//ゲージ
	Draw::Draw2D(34, m_x - m_ani_time, m_y);

	//メーター
	Draw::Draw2D(31, m_x2, m_y2);
}