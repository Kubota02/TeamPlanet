#pragma once
//Žg—p‚·‚éƒwƒbƒ_
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//”wŒiƒNƒ‰ƒX
class CBack :public CObj
{
public:
	CBack();
	~CBack();
	void Action();
	void Draw();
private:
	float m_x1;	//”wŒi1‚ÌXˆÊ’u
	float m_x2;	//”wŒi2‚ÌXˆÊ’u
	float m_y;	//YˆÊ’u
};