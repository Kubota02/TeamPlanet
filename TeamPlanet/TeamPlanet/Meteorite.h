#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

//隕石クラス
class CMeteorite :public CObj
{
public:
	CMeteorite();
	~CMeteorite();
	void Action();
	void Draw();
private:
	float m_x;	//位置
	float m_y;
	float m_vx;	//移動ベクトル
	float m_vy;

	HitBox* m_p_hit_box;//当たり判定
};