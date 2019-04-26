//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Bullet.h"
#include "Audio.h"

extern int g_SceneChange;
extern bool g_key_flag;

CHero::CHero()
{
	//主人公の初期位置
	m_x = 0.0f;
	m_y = 250.0f;

	//初期移動方向
	m_vx = 0.0f;
	m_vy = 0.0f;

	//弾丸発射制御用
	m_f = true;

	//体力
	m_hp = 100;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(120.0f, 80.0f);
	m_p_hit_box->SetElement(HERO);		//属性設定
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CHero::~CHero()
{

}

void CHero::Action()
{
	////体力表示
	//for (int i = 0; i < 5; i++)
	//{
	//	heart = new CHeart(i*60.0f, 5.0f);
	//	heart->m_priority = 90;
	//	TaskSystem::InsertObj(heart);
	//}

	//弾丸発射
	if (Input::KeyPush(VK_SPACE))
	{
		if (m_f)
		{
			//弾丸オブジェクト作成
			CBullet* bullet = new CBullet(m_x + 125.0f, m_y + 30.0f);
			bullet->m_priority = 90;
			TaskSystem::InsertObj(bullet);
			Audio::StartMusic(0);

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

	//他の物体と当たった時の処理
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() != HERO)
		{
			m_hp += -20;

			//ハート減らす
			;
		}
	  }

	//体力が無くなった時の削除処理
	if (m_hp <= 0)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
		g_SceneChange = GAMEOVER;
		is_delete = true;
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

void CHero::Draw()
{
	Draw::Draw2D(0, m_x, m_y);
	//Draw::Draw2D(20, m_x + 200.0f, m_y);
}