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
		float m_x;     //�ʒuX
		float m_y;     //�ʒuY
};