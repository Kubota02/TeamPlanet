#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�^�C���A�C�e���I�u�W�F�N�g
class CTimeitem : public CObj
{
	public:
		CTimeitem(float x, float y); //�R���X�g���N�^
		~CTimeitem();                //�f�X�g���N�^
		void Action();               //�A�N�V����
		void Draw();                 //�h���[
	private:
		float m_x;                   //�ʒuX
		float m_y;                   //�ʒuY
		float m_vx;                  //�ړ��x�N�g��X

		HitBox* m_p_hit_box;         //�����蔻��
};