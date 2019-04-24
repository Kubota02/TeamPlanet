#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

#include "EnemyData.h"

//�o�N���X
class CEnemy :public CObj
{
public:
	CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed, int hp, int w, int h,
		int stop_time, int out_time, int shot_pattern, int shot_time, int shot_speed, int item);
	~CEnemy();
	void Action();
	void Draw();
private:
	float x;	//�ʒu
	float y;
	float m_vx;	//�ړ��x�N�g��
	float m_vy;

	int enemy_type; //�G�̎��
	int in_time;	//�o��
	int enemy_speed;//�G�̑���
	int hp;			//HP
	int w;			//�����蔻��̍��W
	int h;
	int stop_time;	//��~
	int out_time;	//�A��
	int shot_pattern;//���˃p�^�[��
	int shot_time;	//����
	int shot_speed;//�e�̃X�s�[�h
	int item;		//�A�C�e��

	HitBox* m_p_hit_box;//�����蔻��
};