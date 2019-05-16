#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//操作説明クラス
class CDescription :public CObj
{
public:
	CDescription();
	~CDescription();
	void Action();
	void Draw();
private:
	float m_x;	//背景位置
	float m_y;

	int m_ani_time;//アニメーション
};