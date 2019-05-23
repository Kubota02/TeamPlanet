#pragma once

//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"

//RankMoonクラス
class CRankM : public CObj
{
	public:
		CRankM();
		~CRankM();
		void Action();
		void Draw();
	private:
		float m_x;
		float m_y;

		int m_ani_time;
};