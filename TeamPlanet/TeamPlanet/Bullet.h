#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�e�ۃN���X
class CBullet : public CObj
{
	public:
		CBullet(float x,float y);     //�R���X�g���N�^
		~CBullet();                   //�f�X�g���N�^
		void Action();                //�A�N�V����
		void Draw();                  //�h���[
	private:
		float m_x;                    //�e�ۂ̈ʒuX
		float m_y;                    //�e�ۂ̈ʒuY
		float m_vx;                   //�ړ��x�N�g��X

		int m_damage;                 //�e�ۂ̃_���[�W��

		int m_ani_time;               //�A�j���[�V�����^�C��

		HitBox* m_p_hit_box;          //�����蔻��
};