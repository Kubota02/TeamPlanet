//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Bullet.h"

extern int g_SceneNumber;
extern bool g_key_flag;

CHero::CHero()
{
	//ランダムで初期値を決める
	/*m_x = rand() % 300 + 100;
	m_y = rand() % 300 + 100;*/

	//主人公の初期位置
	m_x = 0.0f;
	m_y = 250.0f;

	//初期移動方向
	m_vx = 0.0f;
	m_vy = 0.0f;

	//弾丸発射制御用
	m_f = true;

	//HEROオブジェクトの各当たり判定の属性をバラバラにする
	static int count = 0;
	count++;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(120.0f, 80.0f);
	m_p_hit_box->SetElement(count);		//属性をcountにする
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CHero::~CHero()
{

}

void CHero::Action()
{
	//弾丸発射
	if (Input::KeyPush(VK_SPACE))
	{
		if (m_f)
		{
			//弾丸オブジェクト作成
			CBullet* bullet = new CBullet(m_x + 120.0f, m_y + 30.0f);
			bullet->m_priority = 90;
			TaskSystem::InsertObj(bullet);

			m_f = false;
		}
	}
	else
	{
		m_f = true;
	}

	//初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//右
	if (Input::KeyPush(VK_RIGHT))
	{
		m_vx += 3.0f;
	}
	//左
	if (Input::KeyPush(VK_LEFT))
	{
		m_vx -= 3.0f;
	}
	//上
	if (Input::KeyPush(VK_UP))
	{
		m_vy -= 3.0f;
	}
	//下
	if (Input::KeyPush(VK_DOWN))
	{
		m_vy += 3.0f;
	}

	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = m_vx*m_vx + m_vy*m_vy;
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
		m_vy = 3.0f / r * m_vy;
	}

	//移動方向に位置を加える
	m_x += m_vx;
	m_y += m_vy;

	//領域外に出ない処理
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}
	if (m_x > 800.0f - 120.0f)
	{
		m_x = 680.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_y > 600.0f - 80.0f)
	{
		m_y = 520.0f;
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);

	//削除実行
	//if (Input::KeyPush('Z'))
	//{
	//	is_delete = true;				//オブジェクトの削除
	//	m_p_hit_box->SetDelete(true);	//当たり判定の削除
	//}

	//領域に出ないように反射させる
	/*if (m_x <			 0.0f) m_vx = +1.0f;
	if (m_x > 800.0f - 256.0f) m_vx = -1.0f;
	if (m_y <			 0.0f) m_vy = +1.0f;
	if (m_y > 600.0f - 256.0f) m_vy = -1.0f;*/
}

void CHero::Draw()
{
	//描画
	Draw::Draw2D(0, m_x, m_y);
}