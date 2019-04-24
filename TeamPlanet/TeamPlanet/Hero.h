#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

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

	int m_hp;	//体力

	int m_ani_time;  //主人公アニメーション

	HitBox* m_p_hit_box;//当たり判定
};