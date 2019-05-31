#pragma once

//使用ヘッダー
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"

//Scoreクラス
class CScore : public CObj
{
	public:
		CScore();       //コンストラクタ
		~CScore();      //デストラクタ
		void Action();  //アクション
		void Draw();    //ドロー
	private:
		float m_x1;     //位置X
		float m_y1;     //位置Y
		float m_x2;     //点数位置X
		float m_y2;     //点数位置Y

		wchar_t str[128]; //文字列用
};