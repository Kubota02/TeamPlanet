#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�G�e�ۃN���X
class CEnemybullet : public CObj
{
	public:
		CEnemybullet(float x,float y); //�R���X�g���N�^
		~CEnemybullet();               //�f�X�g���N�^
		void Action();                 //�A�N�V����
		void Draw();                   //�h���[
	private:
		float m_x;                     //�ʒuX
		float m_y;                     //�ʒuY
		float m_vx;                    //�ړ��x�N�g��X
		float m_vy;                    //�ړ��x�N�g��Y

		HitBox* m_p_hit_box;           //�����蔻��
};