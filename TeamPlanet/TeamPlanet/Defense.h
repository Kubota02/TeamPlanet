#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

#include "Hero.h"

//シールドアイテムクラス
class CDefense : public CObj
{
public:
	CDefense(int x, int y);
	~CDefense();
	void Action();
	void Draw();
private:
	int m_x;		//位置
	int m_y;
	int m_vx;		//移動ベクトル

	HitBox* m_p_hit_box;//当たり判定
};