#pragma once

//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//主人公爆発エフェクトクラス
class CHeroBoom : public CObj
{
	public:
		CHeroBoom(float x, float y);
		~CHeroBoom();
		void Action();
		void Draw();
	private:
		float m_x; //X位置
		float m_y; //Y位置

		int m_ani_time; //アニメーション制御用
};