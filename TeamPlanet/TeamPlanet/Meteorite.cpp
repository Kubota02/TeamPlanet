//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Meteorite.h"

CMeteorite::CMeteorite()
{
	//隕石の初期位置
	m_x = 800.0f;
	m_y = 300.0f;

	//初期移動方向
	m_vx = -1.0f;

	//隕石の初期耐久
	endurance = 60;

	//Meteoriteオブジェクトの各当たり判定の属性をバラバラにする
	static int count = 0;
	count++;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(100.0f, 100.0f);
	m_p_hit_box->SetElement(count);		//属性をcountにする
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CMeteorite::~CMeteorite()
{

}

void CMeteorite::Action()
{
	//領域外に出たらオブジェクト破棄
	if (m_x < -100.0f)
	{
		is_delete = true;				//オブジェクトの削除
		m_p_hit_box->SetDelete(true);	//当たり判定の削除
	}

	//移動方向に位置*速度を加える
	m_x += m_vx*2.0f;

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

void CMeteorite::Draw()
{
	//描画
	Draw::Draw2D(3, m_x, m_y);
}