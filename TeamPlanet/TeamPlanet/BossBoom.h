#pragma once

//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

class CBossBoom : public CObj
{
public:
	CBossBoom(float x, float y);
	~CBossBoom();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;

	bool boom_flag;

	int m_ani_time;
};