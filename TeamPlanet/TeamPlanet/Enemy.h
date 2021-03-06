#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"
#include "Audio.h"
#include "EnemyData.h"
#include "Defense.h"
#include "Heartitem.h"
#include "Timeitem.h"
#include "Speedup.h"
#include "Time.h"
#include "EnemyBoom.h"
#include "BossBoom.h"

//敵クラス
class CEnemy :public CObj
{
public:
	CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed, int hp, int w, int h,
		int stop_time, int out_time, int item, int point);
	~CEnemy();
	void Action();
	void Draw();
private:
	float x;	//位置
	float y;
	float m_vx;	//移動ベクトル
	float m_vy;

	int m_count;//出現用カウント

	int enemy_type; //敵の種類
	int in_time;	//出現
	int enemy_speed;//敵の速さ
	int hp;			//HP
	int w;			//当たり判定の座標
	int h;
	int stop_time;	//停止
	int out_time;	//帰還
	int item;		//アイテム
	int point;		//得点

	HitBox* m_p_hit_box;//当たり判定
};