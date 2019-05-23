#pragma once

//使用ヘッダー
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//ゲージクラス
class CGauge : public CObj
{
	public:
		CGauge();      //コンストラクタ
		~CGauge();     //デストラクタ
		void Action(); //アクション
		void Draw();   //ドロー
	private:
		float m_x;		//ゲージの位置
		float m_x3;
		float m_y;
		float m_x2;		//メーターの位置
		float m_y2;

		int m_ani_time;//アニメーション
};