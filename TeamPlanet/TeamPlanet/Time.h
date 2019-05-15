#pragma once

//�g�p�w�b�_�[
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"

//Time�N���X
class CTime : public CObj
{
	public:
		CTime();        //�R���X�g���N�^
		~CTime();       //�f�X�g���N�^
		void Action();  //�A�N�V����
		void Draw();    //�h���[

		int GetTime() { return m_time; }
		void TimeUp();

	private:
		float m_x;      //�ʒuX
		float m_y;      //�ʒuY
		int m_time;     //����
		int second;     //�b
		wchar_t str[128];//�����񉻗p
};