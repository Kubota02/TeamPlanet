#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"

//Score�N���X
class CScore : public CObj
{
	public:
		CScore();       //�R���X�g���N�^
		~CScore();      //�f�X�g���N�^
		void Action();  //�A�N�V����
		void Draw();    //�h���[
	private:
		float m_x1;     //�ʒuX
		float m_y1;     //�ʒuY
		float m_x2;     //�_���ʒuX
		float m_y2;     //�_���ʒuY

		wchar_t str[128]; //������p
};