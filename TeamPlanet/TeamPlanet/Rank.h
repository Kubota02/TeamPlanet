#pragma once

#include "Draw2DPolygon.h"
#include "Audio.h"
#include "Input.h"
#include "TaskSystem.h"

class CRank : public CObj
{
	public:
		CRank();       //�R���X�g���N�^
		~CRank();      //�f�X�g���N�^
		void Action(); //�A�N�V����
		void Draw();   //�h���[
	private:
		float m_x;     //�ʒuX
		float m_y;     //�ʒuY
};