#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//�n�[�g�N���X
class CHeart : public CObj
{
	public:
		CHeart();      //�R���X�g���N�^
		~CHeart();                    //�f�X�g���N�^
		void Action();                //�A�N�V����
		void Draw();                  //�h���[
	private:
		float m_x;                    //�ʒuX
		float m_y;                    //�ʒuY
};