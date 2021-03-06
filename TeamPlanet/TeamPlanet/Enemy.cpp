//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Enemy.h"

extern int g_SceneChange;
extern int heart_num;
extern int g_time;
int total;
int e_hp;
int enemy;

CEnemy::CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed,
	int hp, int w, int h, int stop_time, int out_time, int item, int point)
{
	//敵の種類
	this->enemy_type = enemy_type;
	enemy = enemy_type;

	//出現
	this->in_time = in_time;

	//座標
	this->x = x;
	this->y = y;

	//敵の速さ
	this->enemy_speed = enemy_speed;

	//敵のHP
	this->hp = hp;
	e_hp = hp;

	//当たり判定の座標
	this->w = w;
	this->h = h;

	//停止
	this->stop_time = stop_time;

	//帰還
	this->out_time = out_time;

	//アイテム
	this->item = item;

	//得点
	this->point = point;

	//出現カウント
	m_count = 0;

	//初期移動方向
	m_vx = -1.0f;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);
}

CEnemy::~CEnemy()
{

}

void CEnemy::Action()
{
	m_count++;

	//領域外にいるとき
	if (x >= 800)
	{
		m_p_hit_box->SetInvisible(true);	//無敵モード
	}
	else
	{
		//月の当たり判定
		if (enemy_type == 5)
		{
			m_p_hit_box->SetPos(x + 20, y + 25);
			m_p_hit_box->SetWH(w - 260, h - 75);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//土星の当たり判定
		else if (enemy_type == 6)
		{
			m_p_hit_box->SetPos(x + 120, y + 40);
			m_p_hit_box->SetWH(w - 270, h - 75);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//天王星の当たり判定
		else if (enemy_type == 7)
		{
			m_p_hit_box->SetPos(x + 30, y + 110);
			m_p_hit_box->SetWH(w - 240, h - 65);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//塵の当たり判定
		else if (enemy_type == 2)
		{
			m_p_hit_box->SetPos(x + 10, y + 10);
			m_p_hit_box->SetWH(w -15, h - 15);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//隕石1の当たり判定
		else if (enemy_type == 3)
		{
			m_p_hit_box->SetPos(x + 17, y + 23);
			m_p_hit_box->SetWH(w - 25, h - 36);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//衛星の当たり判定
		else if (enemy_type == 16)
		{
			m_p_hit_box->SetPos(x + 17, y + 30);
			m_p_hit_box->SetWH(w - 45, h - 70);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}

		//ソーラーの当たり判定
		else if (enemy_type == 17)
		{
			m_p_hit_box->SetPos(x + 8, y + 10);
			m_p_hit_box->SetWH(w - 30, h - 30);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//アンテナの当たり判定
		else if (enemy_type == 18)
		{
			m_p_hit_box->SetPos(x + 9, y + 7);
			m_p_hit_box->SetWH(w - 12, h - 8);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//隕石2の当たり判定
		else if (enemy_type == 19)
		{
			m_p_hit_box->SetPos(x + 25, y + 27);
			m_p_hit_box->SetWH(w - 45, h - 40);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//敵1の当たり判定
		else if (enemy_type == 10)
		{
			m_p_hit_box->SetPos(x + 15, y + 30);
			m_p_hit_box->SetWH(w - 25, h - 50);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		//敵2の当たり判定
		else if (enemy_type == 11)
		{
			m_p_hit_box->SetPos(x + 10, y + 30);
			m_p_hit_box->SetWH(w - 15, h - 45);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
		else
		{
			//当たり判定
			m_p_hit_box->SetPos(x, y);
			m_p_hit_box->SetWH(w, h);
			m_p_hit_box->SetElement(ENEMY);	//属性設定
			m_p_hit_box->SetInvisible(false);	//無敵モード無効
		}
	}

	//領域外に出たらオブジェクト破棄
	if (x < -100.0f)
	{
		is_delete = true;				//オブジェクトの削除
		m_p_hit_box->SetDelete(true);	//当たり判定の削除
	}

	//enemy_typeが5,6,7以外なら移動し続ける
	if (enemy_type != 5 && enemy_type != 6 && enemy_type != 7)
	{
		if (in_time < m_count)
		{
			//移動方向に位置*速度を加える
			x += m_vx*enemy_speed;
		}
	}
	else
	{
		//出現してから停止するまで
		if (in_time < m_count && m_count < stop_time)
		{
			//BossBGMスタート
			Audio::StopLoopMusic(7);
			Audio::StartLoopMusic(4);
			Audio::LoopMusicVolume(4, 0.03f);

			//移動方向に位置*速度を加える
			x += m_vx*enemy_speed;
		}
		//帰還時間になったとき
		else if (out_time < m_count)
		{
			//移動方向に位置*速度を加える
			x -= m_vx*enemy_speed;

			//領域外に出たとき
			if (x > 800)
			{
				//ボスミュージック止める
				Audio::StopLoopMusic(4);
				Audio::StartLoopMusic(7);
				Audio::LoopMusicVolume(7, 0.03f);
				is_delete = true;				//オブジェクトの削除
				m_p_hit_box->SetDelete(true);	//当たり判定の削除
			}
		}
	}

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
			//Bossでない場合、体力を0にする
			if (enemy_type != 5 && enemy_type != 6 && enemy_type != 7)
			{
				hp = 0;
			}
			else
			{
				;
			}
		}
		//自分のHPが0かつ弾丸に当たった時
		if (hp <= 0 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			//合計に得点を加算
 			total += point;
		}
	}

	//空の情報でない場合
	if (enemy_type != 0)
	{
		//HPが無くなった時の削除処理
		if (hp <= 0)
		{
			is_delete = true;
			m_p_hit_box->SetDelete(true);

			//敵爆発音
			Audio::StartMusic(3);

			//Bossでない場合
			if (enemy_type != 5 && enemy_type != 6 && enemy_type != 7)
			{
				//爆発エフェクト生成
				if (enemy_type == 2)
				{
					CEnemyBoom* e_boom = new CEnemyBoom(x - 30, y - 30);
					e_boom->m_priority = 90;
					TaskSystem::InsertObj(e_boom);
				}
				else if (enemy_type == 17)
				{
					CEnemyBoom* e_boom = new CEnemyBoom(x - 30, y - 30);
					e_boom->m_priority = 90;
					TaskSystem::InsertObj(e_boom);
				}
				else if (enemy_type == 18)
				{
					CEnemyBoom* e_boom = new CEnemyBoom(x - 30, y - 30);
					e_boom->m_priority = 90;
					TaskSystem::InsertObj(e_boom);
				}
				else
				{
					CEnemyBoom* e_boom = new CEnemyBoom(x, y);
					e_boom->m_priority = 90;
					TaskSystem::InsertObj(e_boom);
				}
			}
			else
			{
				Audio::StopLoopMusic(4);

				//BossBGMスタート
				Audio::StartMusic(17);
				Audio::SEMusicVolume(17, 1.8f);

				//爆発エフェクト生成
				if (enemy_type == 5)
				{
					CBossBoom* b_boom = new CBossBoom(x, y);
					b_boom->m_priority = 90;
					TaskSystem::InsertObj(b_boom);
				}
				if (enemy_type == 6)
				{
					CBossBoom* b_boom = new CBossBoom(x + 85, y + 15);
					b_boom->m_priority = 90;
					TaskSystem::InsertObj(b_boom);
				}
				if (enemy_type == 7)
				{
					CBossBoom* b_boom = new CBossBoom(x - 20, y + 80);
					b_boom->m_priority = 90;
					TaskSystem::InsertObj(b_boom);
				}

				//BGMスタート
				Audio::StartLoopMusic(7);
				Audio::LoopMusicVolume(7, 0.03f);
			}

			//主人公の弾丸に当たった時
			for (int i = 0; i < 10; i++)
			{
				if (m_p_hit_box->GetHitData()[i] == nullptr)
					continue;

				//アイテムが1かつ弾丸に当たったとき
				if (item == 1 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//シールドアイテムオブジェクト作成
					CDefense* d = new CDefense(x, y);
					d->m_priority = 90;
					TaskSystem::InsertObj(d);
				}
				//アイテムが2かつ弾丸に当たったとき
				else if (item == 2 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//スピードアップアイテムオブジェクト作成
					CSpeedup* s = new CSpeedup(x, y);
					s->m_priority = 90;
					TaskSystem::InsertObj(s);
				}
				//アイテムが3かつ弾丸に当たったとき
				else if (item == 3 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//ハートアイテムオブジェクト作成
					CHeartitem* h = new CHeartitem(x, y);
					h->m_priority = 90;
					TaskSystem::InsertObj(h);
				}
			}
		}
	}
	else
	{
		//何もしない
		;
	}

	//主人公のHPがなくなったら破棄
	if (heart_num == 0)
	{
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	//制限時間が無くなった時の削除処理
	if (g_time == 0)
	{
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	//得点が目標得点に到達したらゲームクリア
	if (total >= 7300)
	{
		Audio::StopLoopMusic(7);
		g_SceneChange = GAMECLEAR;
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	if (enemy_type == 5)
	{
		//月の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 20, y + 25);
	}
	else if (enemy_type == 6)
	{
		//土星の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 120, y + 40);
	}
	else if (enemy_type == 7)
	{
		//天王星の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 30, y + 110);
	}
	else if (enemy_type == 2)
	{
		//塵の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 10, y + 10);
	}
	else if (enemy_type == 3)
	{
		//隕石1の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 17, y + 23);
	}
	else if (enemy_type == 16)
	{
		//衛星の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 17, y + 30);
	}
	else if (enemy_type == 17)
	{
		//ソーラーの当たり判定の位置更新
		m_p_hit_box->SetPos(x + 8, y + 10);
	}
	else if (enemy_type == 18)
	{
		//アンテナの当たり判定の位置更新
		m_p_hit_box->SetPos(x + 9, y + 7);
	}
	else if (enemy_type == 19)
	{
		//隕石2の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 25, y + 27);
	}
	else if (enemy_type == 10)
	{
		//敵1の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 15, y + 30);
	}
	else if (enemy_type == 11)
	{
		//敵2の当たり判定の位置更新
		m_p_hit_box->SetPos(x + 10, y + 30);
	}
	else
	{
		//当たり判定の位置更新
		m_p_hit_box->SetPos(x, y);
	}
}

void CEnemy::Draw()
{
	//領域外なら表示しない
	if (x >= 800)
	{
		return;
	}
	else
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
		if (enemy_type == 5)
		{
			//月
			Draw::Draw2D(enemy_type, x, y);
		}
		if (enemy_type == 6)
		{
			//土星
			Draw::Draw2D(enemy_type, x, y);
		}
		if (enemy_type == 7)
		{
			//天王星
			Draw::Draw2D(enemy_type, x, y);
		}
	}
}