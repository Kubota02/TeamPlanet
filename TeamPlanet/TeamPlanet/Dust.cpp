//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Dust.h"

extern int g_SceneNumber;
extern bool g_key_flag;

CDust::CDust()
{
	//塵の初期位置
	//m_x = 850.0f;
	//m_y = 200.0f;
	m_x = rand() % 1100 + 1100;
	m_y = rand() % 600;

	//初期移動方向
	m_vx = -1.0f;

	//塵の初期耐久
	endurance = 40;

	//Dustオブジェクトの各当たり判定の属性をバラバラにする
	static int count = 0;
	count++;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 50.0f);
	m_p_hit_box->SetElement(DUST);		//属性設定
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CDust::~CDust()
{

}

void CDust::Action()
{
	//領域外に出たらオブジェクト破棄
	if (m_x < -50.0f)
	{
		is_delete = true;				//オブジェクトの削除
		m_p_hit_box->SetDelete(true);	//当たり判定の削除
	}

	//移動方向に位置*速度を加える
	m_x += m_vx*2.0f;

	//弾丸に当たった時のダメージ処理
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			/*is_delete = true;
			m_p_hit_box->SetDelete(true);*/
			endurance += -20;
		}
	}

	//耐久力が無くなった時の削除処理
	if (endurance == 0)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

void CDust::Draw()
{
	//描画
	Draw::Draw2D(2, m_x, m_y);
}