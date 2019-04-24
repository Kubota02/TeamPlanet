#pragma once

//使用ヘッダー
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//ハートクラス
class CHeart : public CObj
{
	public:
		CHeart(float x,float y);      //コンストラクタ
		~CHeart();                    //デストラクタ
		void Action();                //アクション
		void Draw();                  //ドロー
	private:
		float m_x;                    //位置X
		float m_y;                    //位置Y
};