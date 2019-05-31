#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"
#include "Heart.h"
#include "Defense.h"
#include "Speedup.h"

//��l���N���X
class CHero :public CObj
{
public:
	CHero();
	~CHero();
	void Action();
	void Draw();

private:
	float m_x;	//�ʒu
	float m_y;
	float m_vx;	//�ړ��x�N�g��
	float m_vy;

	bool m_f;   //�e�۔��ː���p

	int d_time;//���ԊǗ��p
	bool defense_flag;//�V�[���h�A�C�e���̐���p

	int s_time;//���ԊǗ��p
	bool speed_flag;//�X�s�[�h�A�b�v�A�C�e���̐���p

	bool time_flag;//�^�C���A�C�e���̐���p
	bool heart_flag;//�n�[�g�A�C�e���̐���p

	bool boom_flag; //�G�t�F�N�g�p

	int m_boom_ani; //�����p

	HitBox* m_p_hit_box;//�����蔻��
};