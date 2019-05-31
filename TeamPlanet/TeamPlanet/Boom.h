#pragma once

//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

class CBoom : public CObj
{
	public:
		CBoom(float x, float y);
		~CBoom();
		void Action();
		void Draw();
	private:
		float m_x;
		float m_y;

		int m_ani_time;
};