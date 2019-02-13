//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Dust.h"

CDust::CDust()
{
	//主人公の初期位置
	m_x = 800.0f;
	m_y = 200.0f;

	//初期移動方向
	m_vx = -1.0f;
	//m_vy = -1.0f;

	//HEROオブジェクトの各当たり判定の属性をバラバラにする
	static int count = 0;
	count++;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 50.0f);
	m_p_hit_box->SetElement(count);		//属性をcountにする
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CDust::~CDust()
{

}

void CDust::Action()
{
	//領域外に出たらオブジェクト破棄
	if (m_x < 0.0f)
	{
		is_delete = true;				//オブジェクトの削除
		m_p_hit_box->SetDelete(true);	//当たり判定の削除
	}

	//移動方向に位置*速度を加える
	m_x += m_vx*2.0f;
	//m_y += m_vy*5.0f;

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

void CDust::Draw()
{
	//描画
	Draw::Draw2D(2, m_x, m_y);
}