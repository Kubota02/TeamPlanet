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
		void SetTime(int t) { time += t; }

	private:
		float m_x;      //位置X
		float m_y;      //位置Y
		int second;     //秒
		wchar_t str[128];//文字列化用

		int m_time;
		int time;   //残り時間
};