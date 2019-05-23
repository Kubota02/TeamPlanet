#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�X�s�[�h�A�b�v�A�C�e���N���X
class CSpeedup : public CObj
{
public:
	CSpeedup(int x, int y);
	~CSpeedup();
	void Action();
	void Draw();
private:
	float m_x;		//�ʒu
	float m_y;
	float m_vx;		//�ړ��x�N�g��

	HitBox* m_p_hit_box;//�����蔻��
};