#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�Q�[���Z���N�g�N���X
class CSelect :public CObj
{
public:
	CSelect();
	~CSelect();
	void Action();
	void Draw();
private:
	float m_x;	//�ʒu
	float m_y;
	unsigned int m_cursor; //�J�[�\���ʒu
	unsigned int m_BefCursor; //�O�̃J�[�\���ʒu
	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p
	int m_ani_time;//�A�C�R���ύX�A�j���[�V����
};