#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//タイトルクラス
class CTitle :public CObj
{
public:
	CTitle();
	~CTitle();
	void Action();
	void Draw();
private:
	float m_x;	//背景位置
	float m_y;
	float m_x2;	//宇宙船位置
	float m_y2;
	float m_vx;

	int m_ani_time;//アニメーション
};