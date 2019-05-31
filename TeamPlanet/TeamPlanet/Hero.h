#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"
#include "Heart.h"
#include "Defense.h"
#include "Speedup.h"

//主人公クラス
class CHero :public CObj
{
public:
	CHero();
	~CHero();
	void Action();
	void Draw();

private:
	float m_x;	//位置
	float m_y;
	float m_vx;	//移動ベクトル
	float m_vy;

	bool m_f;   //弾丸発射制御用

	int d_time;//時間管理用
	bool defense_flag;//シールドアイテムの制御用

	int s_time;//時間管理用
	bool speed_flag;//スピードアップアイテムの制御用

	bool time_flag;//タイムアイテムの制御用
	bool heart_flag;//ハートアイテムの制御用

	bool boom_flag; //エフェクト用

	int m_boom_ani; //爆発用

	HitBox* m_p_hit_box;//当たり判定
};