#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//�Q�[�W�N���X
class CGauge : public CObj
{
	public:
		CGauge();      //�R���X�g���N�^
		~CGauge();     //�f�X�g���N�^
		void Action(); //�A�N�V����
		void Draw();   //�h���[
	private:
		float m_x;		//�Q�[�W�̈ʒu
		float m_x3;
		float m_y;
		float m_x2;		//���[�^�[�̈ʒu
		float m_y2;

		int m_ani_time;//�A�j���[�V����
};