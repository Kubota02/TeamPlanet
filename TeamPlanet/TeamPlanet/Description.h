#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//��������N���X
class CDescription :public CObj
{
public:
	CDescription();
	~CDescription();
	void Action();
	void Draw();
private:
	float m_x;	//�w�i�ʒu
	float m_y;

	int m_ani_time;//�A�j���[�V����
};