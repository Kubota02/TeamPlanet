//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Bullet.h"
#include "Audio.h"
#include "Time.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int heart_num;
extern int total;
extern CTime* g_time;
int h_hp = 100;	//体力

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
	h_hp = 100;

	//効果時間用
	d_time = 0;
	s_time = 0;

	//アイテム効果の制御用
	defense_flag = false;
	time_flag = false;
	heart_flag = false;
	speed_flag = false;

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
	//初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	if (d_time != 0)
	{
		d_time++;
	}
	if (s_time != 0)
	{
		s_time++;
	}

	//弾丸発射
	if (Input::KeyPush('L'))
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

	//右
	if (Input::KeyPush('D'))
	{
		m_vx += 2.0f;
	}
	//左
	if (Input::KeyPush('A'))
	{
		m_vx -= 2.0f;
	}
	//上
	if (Input::KeyPush('W'))
	{
		m_vy -= 2.0f;
	}
	//下
	if (Input::KeyPush('S'))
	{
		m_vy += 2.0f;
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
		m_vx = 2.0f / r * m_vx;
		m_vy = 2.0f / r * m_vy;
	}

	//他の物体と当たった時の処理
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() == ENEMY)
		{
			h_hp += -20;

			//ハート減らす
			if (heart_num > 0)
				heart_num += -1;

			if (h_hp <= 0)
			{
				h_hp = 0;
			}
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == DEFENSE)
		{
			defense_flag = true;
			d_time++;
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == LIFEUP)
		{
			heart_flag = true;
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == TIMEUP)
		{
			time_flag = true;
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == SPEEDUP)
		{
			speed_flag = true;
			s_time++;
		}
	  }

	//体力が無くなった時の削除処理
	if (h_hp == 0)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
		Audio::StopLoopMusic(7);
		Audio::StartMusic(2);
		g_SceneChange = GAMEOVER;
	}

	//シールド
	if (defense_flag)
	{
		m_p_hit_box->SetInvisible(true);
		defense_flag = true;

		if (d_time == 180)
		{
			m_p_hit_box->SetInvisible(false);
			d_time = 0;
			defense_flag = false;
		}
	}
	else
	{
		m_p_hit_box->SetInvisible(false);
		defense_flag = false;
	}

	//ハートアイテム効果
	if (heart_flag == true)
	{
		if (heart_num == 5)
			;
		else
		{
			heart_num += 1;
			heart_flag = false;
		}
	}

	//タイムアイテム効果
	if (time_flag == true)
	{
		CTime* time = (CTime*)TaskSystem::GetObj(TIME);
		time->SetTime();
		time->AddTime(5);
		time_flag = false;
	}

	//スピードアップアイテム効果
	if (speed_flag == true)
	{
		m_x += m_vx * 2;
		m_y += m_vy * 2;

		speed_flag = true;

		if (s_time == 180)
		{
			//移動方向に位置を加える
			m_x += m_vx;
			m_y += m_vy;
			s_time = 0;

			speed_flag = false;
		}
	}
	else
	{
		//移動方向に位置を加える
		m_x += m_vx;
		m_y += m_vy;

		speed_flag = false;
	}

	//移動方向に位置を加える
	m_x += m_vx;
	m_y += m_vy;

	//得点が目標得点に到達したら自身を削除
	if (total >= 1000)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

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
}

void CHero::Draw()
{
	switch (heart_num)
	{
		case 5:
		case 4:
			Draw::Draw2D(0, m_x, m_y);
			break;
		case 3:
		case 2:
			Draw::Draw2D(12, m_x, m_y);
			break;
		case 1:
			Draw::Draw2D(13, m_x, m_y);
			break;
	}
}