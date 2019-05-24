#pragma once

//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"

//Warningクラス
class CWarning : public CObj
{
	public:
		CWarning();    //コンストラクタ
		~CWarning();    //デストラクタ
		void Action(); //アクション
		void Draw();   //ドロー
	private:
		float m_x1;    //warning1つ目
		float m_y1;    //warning1つ目
		float m_x2;    //warning2つ目
		float m_y2;    //warning2つ目

		int m_ani_time;
		int m_time;
};