//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Bullet.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CBullet::CBullet(float x,float y)
{
	//弾丸の初期位置
	m_x = x;
	m_y = y;

	//アニメーションタイム
	m_ani_time = 0;

	//弾丸の移動ベクトル初期化
	m_vx = 0.0f;

	//弾丸のダメージ量初期化
	m_damage = 20;

	//ヒットボックス作成
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(60.0f, 35.0f);
	m_p_hit_box->SetElement(BULLET);   //属性設定
	m_p_hit_box->SetInvisible(false);  //無敵モード無効
}

//デストラクタ
CBullet::~CBullet()
{

}

//アクション
void CBullet::Action()
{
	//速度
	m_vx += 3.0f;

	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = m_vx*m_vx;
	r = sqrt(r);//rをルートを求める

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		;
	}
	else
	{
		//正規化を行う
		m_vx = 3.0f / r * m_vx;
	}

	//位置の更新
	m_x += m_vx*5;

	//領域外に出たら削除
	if (m_x > 800.0f)
	{
		is_delete = true;              //オブジェクトの削除
		m_p_hit_box->SetDelete(true);  //当たり判定の削除
	}

	//弾丸が他の物体と当たった時に削除
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() != BULLET)
		{
			is_delete = true;             //オブジェクトの削除
			m_p_hit_box->SetDelete(true); //当たり判定の削除	
		}
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

//ドロー
void CBullet::Draw()
{
	//アニメーション
	m_ani_time++;

	if (m_ani_time == 12)
	{
		m_ani_time = 0;
	}

	//Draw::Draw2D(1, m_x, m_y);
	if (m_ani_time <= 6)
	{
		Draw::Draw2D(1, m_x, m_y);
	}
	if (m_ani_time > 6 && m_ani_time <= 12)
	{
		Draw::Draw2D(32, m_x, m_y);
	}
}