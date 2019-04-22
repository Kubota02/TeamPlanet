#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

//�G2�N���X
class CEnemy2 : public CObj
{
	public:
		CEnemy2();       //�R���X�g���N�^
		~CEnemy2();      //�f�X�g���N�^
		void Action();   //�A�N�V����
		void Draw();     //�h���[
	private:
		float m_x;       //�ʒuX
		float m_y;       //�ʒuY
		float m_vx;      //�ړ��x�N�g��X
		float m_vy;      //�ړ��x�N�g��Y

		int endurance;   //�ϋv��

		HitBox* m_p_hit_box; //�����蔻��
};