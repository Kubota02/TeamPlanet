#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

//�G1�N���X
class CEnemy1 : public CObj
{
	public:
		CEnemy1();      //�R���X�g���N�^
		~CEnemy1();     //�f�X�g���N�^
		void Action();  //�A�N�V����
		void Draw();    //�h���[
	private:
		float m_x;      //�ʒuX
		float m_y;      //�ʒuY
		float m_vx;     //�ړ��x�N�g��X
		float m_vy;     //�ړ��x�N�g��Y

		int endurance;  //�ϋv��

		HitBox* m_p_hit_box; //�����蔻��
};