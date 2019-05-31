#pragma once

//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//��l�������G�t�F�N�g�N���X
class CHeroBoom : public CObj
{
	public:
		CHeroBoom(float x, float y);
		~CHeroBoom();
		void Action();
		void Draw();
	private:
		float m_x; //X�ʒu
		float m_y; //Y�ʒu

		int m_ani_time; //�A�j���[�V��������p
};