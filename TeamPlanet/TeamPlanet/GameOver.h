#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//�^�C�g���N���X
class CGameOver :public CObj
{
public:
	CGameOver();
	~CGameOver();
	void Action();
	void Draw();
private:
	float m_x;	//�w�i�ʒu
	float m_y;

	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p
	bool rank_key_flag; //�����N����p

	int m_ani_time;//�A�j���[�V����
};