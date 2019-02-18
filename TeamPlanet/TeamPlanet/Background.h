#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//背景クラス
class CBackground :public CObj
{
public:
	CBackground();
	~CBackground();
	void Action();
	void Draw();
private:
	float m_x;	//位置
	float m_y;
};