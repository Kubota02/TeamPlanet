#pragma once

#include "Draw2DPolygon.h"
#include "Audio.h"
#include "Input.h"
#include "TaskSystem.h"

class CRank : public CObj
{
	public:
		CRank();       //コンストラクタ
		~CRank();      //デストラクタ
		void Action(); //アクション
		void Draw();   //ドロー
	private:
		float m_x;     //位置X
		float m_y;     //位置Y
};