//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Enemy1.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CEnemy1::CEnemy1()
{
	//敵1の初期位置
	m_x = rand() % 1100 + 1100;
	m_y = rand() % 600;

	//初期移動方向
	m_vx = -1.0f;

	//敵1の初期耐久力
	endurance = 60;

	//ヒットボックス作成
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(100.0f, 100.0f);
	m_p_hit_box->SetElement(ENEMY1);
	m_p_hit_box->SetInvisible(false);
}

//デストラクタ
CEnemy1::~CEnemy1()
{

}

//アクション
void CEnemy1::Action()
{
	//領域外に出たらオブジェクト破棄
	if (m_x < -100.0f)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//移動方向に位置*速度を加える
	m_x += m_vx*2.0f;

	//当たり判定の処理
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		//主人公の弾丸に当たった時
		if (m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			endurance += -20;
		}
		//主人公に当たった時
		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			endurance = 0;
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

//ドロー
void CEnemy1::Draw()
{
	//描画
	Draw::Draw2D(10, m_x, m_y);
}