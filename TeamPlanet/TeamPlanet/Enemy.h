#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

#include "EnemyData.h"

//塵クラス
class CEnemy :public CObj
{
public:
	CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed, int hp, int w, int h,
		int stop_time, int out_time, int shot_pattern, int shot_time, int shot_speed, int item);
	~CEnemy();
	void Action();
	void Draw();
private:
	float x;	//位置
	float y;
	float m_vx;	//移動ベクトル
	float m_vy;

	int enemy_type; //敵の種類
	int in_time;	//出現
	int enemy_speed;//敵の速さ
	int hp;			//HP
	int w;			//当たり判定の座標
	int h;
	int stop_time;	//停止
	int out_time;	//帰還
	int shot_pattern;//発射パターン
	int shot_time;	//発射
	int shot_speed;//弾のスピード
	int item;		//アイテム

	HitBox* m_p_hit_box;//当たり判定
};