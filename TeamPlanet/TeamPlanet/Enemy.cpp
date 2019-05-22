//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Enemy.h"
#include "Audio.h"

extern int g_SceneChange;
extern bool g_key_flag;
int total;
extern int heart_num;

CEnemy::CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed, int hp,
	int w, int h, int stop_time, int out_time, int shot_pattern, int shot_time, int shot_speed, int item, int point)
{
	//敵の種類
	this->enemy_type = enemy_type;

	//出現
	this->in_time = in_time;

	//座標
	this->x = x;
	this->y = y;

	//敵の速さ
	this->enemy_speed = enemy_speed;

	//敵のHP
	this->hp = hp;

	//当たり判定の座標
	this->w = w;
	this->h = h;

	//停止
	this->stop_time = stop_time;

	//帰還
	this->out_time = out_time;

	//発射パターン
	this->shot_pattern = shot_pattern;

	//発射
	this->shot_time = shot_time;

	//弾のスピード
	this->shot_speed = shot_speed;

	//アイテム
	this->item = item;

	//得点
	this->point = point;

	//初期移動方向
	m_vx = -1.0f;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(x, y);
	m_p_hit_box->SetWH(w, h);
	m_p_hit_box->SetElement(ENEMY);	//属性設定
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CEnemy::~CEnemy()
{

}

void CEnemy::Action()
{
	//領域外に出たらオブジェクト破棄
	if (x < -100.0f)
	{
		is_delete = true;				//オブジェクトの削除
		m_p_hit_box->SetDelete(true);	//当たり判定の削除
	}

	//移動方向に位置*速度を加える
	x += m_vx*2.0f;

	//当たり判定の処理
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		//弾丸に当たった時
		if (m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			hp += -20;
		}
		//主人公に当たった時
		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			hp = 0;
		}
		//自分のHPが0かつ弾丸に当たった時
		if (hp <= 0 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
 			total += point;
		}
	}
	if (enemy_type != 0)
	{
		//HPが無くなった時の削除処理
		if (hp <= 0)
		{
			is_delete = true;
			m_p_hit_box->SetDelete(true);
			Audio::StartMusic(3);

			for (int i = 0; i < 10; i++)
			{
				if (m_p_hit_box->GetHitData()[i] == nullptr)
					continue;
				if (item == 1 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//シールドアイテムオブジェクト作成
					CDefense* d = new CDefense(x, y);
					d->m_priority = 90;
					TaskSystem::InsertObj(d);
				}
				else if (item == 2 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					////ハートアイテムオブジェクト作成
					/*CHeartitem* h = new CHeartitem(x, y);
					h->m_priority = 90;
					TaskSystem::InsertObj(h);*/

					//タイムアイテムオブジェクト作成
					/*CTimeitem* t = new CTimeitem(x, y);
					t->m_priority = 90;
					TaskSystem::InsertObj(t);*/

					//スピードアップアイテムオブジェクト作成
					CSpeedup* s = new CSpeedup(x, y);
					s->m_priority = 90;
					TaskSystem::InsertObj(s);
				}
			}
		}
	}
	else
	{
		;
	}

	//主人公のHPがなくなったら破棄
	if (heart_num == 0)
	{
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	//得点が目標得点に到達したらゲームクリア
	if (total >= 50)
	{
		Audio::StopLoopMusic(7);
		g_SceneChange = GAMECLEAR;
		is_delete = true;
	}

	//当たり判定の位置更新
	m_p_hit_box->SetPos(x, y);
}

void CEnemy::Draw()
{
	//描画
	if (enemy_type == 2)
	{
		//塵
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 3)
	{
		//隕石1
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 10)
	{
		//敵1
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 11)
	{
		//敵2
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 16)
	{
		//衛星
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 17)
	{
		//ソーラー
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 18)
	{
		//アンテナ
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 19)
	{
		//隕石2
		Draw::Draw2D(enemy_type, x, y);
	}
}