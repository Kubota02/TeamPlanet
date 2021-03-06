//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Speedup.h"

extern int total;

//コンストラクタ
CSpeedup::CSpeedup(int x, int y)
{
	m_x = x;
	m_y = y;

	m_vx = -3;

	//ヒットボックス作成
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(70.0f, 70.0f);
	m_p_hit_box->SetElement(SPEEDUP);		//属性設定
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
CSpeedup::~CSpeedup()
{

}

//アクション
void CSpeedup::Action()
{
	m_x += m_vx;

	//領域外に出たらオブジェクト破棄
	if (m_x < -50.0f)
	{
		is_delete = true;				//オブジェクトの削除
		m_p_hit_box->SetDelete(true);	//当たり判定の削除
	}

	//当たり判定の処理
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		//主人公に当たった時
		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			Audio::StartMusic(13);
			is_delete = true;				//オブジェクトの削除
			m_p_hit_box->SetDelete(true);	//当たり判定の削除
		}
	}

	//得点が目標得点に到達したら自身を削除
	if (total >= 7300)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

//ドロー
void CSpeedup::Draw()
{
	Draw::Draw2D(30, m_x, m_y);
}