#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�w�i�N���X
class CBack :public CObj
{
public:
	CBack();
	~CBack();
	void Action();
	void Draw();
private:
	float m_x;	//�ʒu
	float m_y;
};