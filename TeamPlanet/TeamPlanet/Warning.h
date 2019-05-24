#pragma once

//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"

//Warning�N���X
class CWarning : public CObj
{
	public:
		CWarning();    //�R���X�g���N�^
		~CWarning();    //�f�X�g���N�^
		void Action(); //�A�N�V����
		void Draw();   //�h���[
	private:
		float m_x1;    //warning1��
		float m_y1;    //warning1��
		float m_x2;    //warning2��
		float m_y2;    //warning2��

		int m_ani_time;
		int m_time;
};