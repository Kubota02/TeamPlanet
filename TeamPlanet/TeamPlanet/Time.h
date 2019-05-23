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
		void AddTime(int t) { time += t; }  //残り時間取得
		void SetTime() { m_time = 0; }      //m_timeリセット

	private:
		float m_x;      //位置X
		float m_y;      //位置Y
		wchar_t str[128];//文字列化用

		int m_time;
		int time;   //残り時間
		int w_time; //warning用
};