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
	private:
		int m_time;      //����
		wchar_t str[128];//�����񉻗p
};