#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//シールドアイテムクラス
class CDefense : public CObj
{
public:
	CDefense(int x, int y);
	~CDefense();
	void Action();
	void Draw();
private:
	float m_x;		//位置
	float m_y;
	float m_vx;		//移動ベクトル

	HitBox* m_p_hit_box;//当たり判定
};