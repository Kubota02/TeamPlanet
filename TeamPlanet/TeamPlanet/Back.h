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
	float m_x1;	//�w�i1��X�ʒu
	float m_x2;	//�w�i2��X�ʒu
	float m_y;	//Y�ʒu
};