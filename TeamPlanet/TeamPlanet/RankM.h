#pragma once

//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"

//RankMoon�N���X
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