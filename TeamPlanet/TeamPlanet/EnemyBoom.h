#pragma once

//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

class CEnemyBoom : public CObj
{
public:
	CEnemyBoom(float x, float y);
	~CEnemyBoom();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;

	bool boom_flag;

	int m_ani_time;
};