#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�^�C�g���N���X
class CTitle :public CObj
{
public:
	CTitle();
	~CTitle();
	void Action();
	void Draw();
private:
	float m_x;	//�w�i�ʒu
	float m_y;
	float m_x2;	//�F���D�ʒu
	float m_y2;
	float m_vx;

	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p
	int m_ani_time;//�A�j���[�V����
};