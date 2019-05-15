#pragma once

//使用ヘッダー
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"

//Timeクラス
class CTime : public CObj
{
	public:
		CTime();        //コンストラクタ
		~CTime();       //デストラクタ
		void Action();  //アクション
		void Draw();    //ドロー

		int GetTime() { return m_time; }
		void TimeUp();

	private:
		float m_x;      //位置X
		float m_y;      //位置Y
		int m_time;     //時間
		int second;     //秒
		wchar_t str[128];//文字列化用
};