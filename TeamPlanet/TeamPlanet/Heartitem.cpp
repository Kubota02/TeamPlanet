//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Heartitem.h"

extern int total;

//コンストラクタ
CHeartitem::CHeartitem(float x, float y)
{
	//位置の初期化
	m_x = x;
	m_y = y;

	//移動ベクトルの初期化
	m_vx = -3.0f;

	//ヒットボックス作成
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(70.0f, 70.0f);
	m_p_hit_box->SetElement(LIFEUP);   //属性設定
	m_p_hit_box->SetInvisible(false);  //無敵モード無効
}

//デストラクタ
CHeartitem::~CHeartitem()
{

}

//アクション
void CHeartitem::Action()
{
	//移動
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
			is_delete = true;				//オブジェクトの削除
			m_p_hit_box->SetDelete(true);	//当たり判定の削除
		}
	}

	//得点が目標得点に到達したら自身を削除
	if (total >= 6670)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

//ドロー
void CHeartitem::Draw()
{
	Draw::Draw2D(38, m_x, m_y);
}