#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

#include "Hero.h"

//�V�[���h�A�C�e���N���X
class CDefense : public CObj
{
public:
	CDefense(int x, int y);
	~CDefense();
	void Action();
	void Draw();
private:
	int m_x;		//�ʒu
	int m_y;
	int m_vx;		//�ړ��x�N�g��

	HitBox* m_p_hit_box;//�����蔻��
};