#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"

//Defense�N���X
class CDefense : public CObj
{
	public:
		CDefense(float x,float y);     //�R���X�g���N�^
		~CDefense();                   //�f�X�g���N�^
		void Action();                 //�A�N�V����
		void Draw();                   //�h���[
	private:
		float m_x;                     //�ʒuX
		float m_y;                     //�ʒuY
};