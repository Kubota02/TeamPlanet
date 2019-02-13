//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Bullet.h"

//コンストラクタ
CBullet::CBullet(float x,float y)
{
	//弾丸の初期位置
	m_x = x;
	m_y = y;

	//弾丸の移動ベクトル初期化
	m_vx = 0.0f;

	//ヒットボックス作成
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 30.0f);
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

	//位置の更新
	m_x += m_vx;

	//領域外に出たら削除
	if (m_x < 800.0f - 50.0f)
	{
		is_delete = true;              //オブジェクトの削除
		m_p_hit_box->SetDelete(true);  //当たり判定の削除
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

//ドロー
void CBullet::Draw()
{
	Draw::Draw2D(1, m_x, m_y);
}