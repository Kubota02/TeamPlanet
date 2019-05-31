#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//タイトルクラス
class CGameClear :public CObj
{
public:
	CGameClear();
	~CGameClear();
	void Action();
	void Draw();
private:
	float m_x;	//背景の位置
	float m_y;

	float m_x2; //宇宙船の位置
	float m_y2;
	float m_vx; //宇宙船の移動ベクトル

	bool key_flag;  //キーが押されているかチェック用
	int m_ani_time;//アニメーション

	bool rank_flag; //ランク管理用
	bool time_flag; //タイム管理用
};