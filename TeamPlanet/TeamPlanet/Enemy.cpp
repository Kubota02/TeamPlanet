//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Enemy.h"
#include "Audio.h"

extern int g_SceneChange;
extern bool g_key_flag;
int total;
extern int heart_num;

CEnemy::CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed, int hp,
	int w, int h, int stop_time, int out_time, int shot_pattern, int shot_time, int shot_speed, int item, int point)
{
	//�G�̎��
	this->enemy_type = enemy_type;

	//�o��
	this->in_time = in_time;

	//���W
	this->x = x;
	this->y = y;

	//�G�̑���
	this->enemy_speed = enemy_speed;

	//�G��HP
	this->hp = hp;

	//�����蔻��̍��W
	this->w = w;
	this->h = h;

	//��~
	this->stop_time = stop_time;

	//�A��
	this->out_time = out_time;

	//���˃p�^�[��
	this->shot_pattern = shot_pattern;

	//����
	this->shot_time = shot_time;

	//�e�̃X�s�[�h
	this->shot_speed = shot_speed;

	//�A�C�e��
	this->item = item;

	//���_
	this->point = point;

	//�����ړ�����
	m_vx = -1.0f;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(x, y);
	m_p_hit_box->SetWH(w, h);
	m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CEnemy::~CEnemy()
{

}

void CEnemy::Action()
{
	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (x < -100.0f)
	{
		is_delete = true;				//�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
	}

	//�ړ������Ɉʒu*���x��������
	x += m_vx*2.0f;

	//�����蔻��̏���
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		//�e�ۂɓ���������
		if (m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			hp += -20;
		}
		//��l���ɓ���������
		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			hp = 0;
		}
		//������HP��0���e�ۂɓ���������
		if (hp <= 0 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
 			total += point;
		}
	}
	if (enemy_type != 0)
	{
		//HP�������Ȃ������̍폜����
		if (hp <= 0)
		{
			is_delete = true;
			m_p_hit_box->SetDelete(true);
			Audio::StartMusic(3);

			for (int i = 0; i < 10; i++)
			{
				if (m_p_hit_box->GetHitData()[i] == nullptr)
					continue;
				if (item == 1 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//�V�[���h�A�C�e���I�u�W�F�N�g�쐬
					CDefense* d = new CDefense(x, y);
					d->m_priority = 90;
					TaskSystem::InsertObj(d);
				}
				else if (item == 2 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					////�n�[�g�A�C�e���I�u�W�F�N�g�쐬
					/*CHeartitem* h = new CHeartitem(x, y);
					h->m_priority = 90;
					TaskSystem::InsertObj(h);*/

					//�^�C���A�C�e���I�u�W�F�N�g�쐬
					/*CTimeitem* t = new CTimeitem(x, y);
					t->m_priority = 90;
					TaskSystem::InsertObj(t);*/

					//�X�s�[�h�A�b�v�A�C�e���I�u�W�F�N�g�쐬
					CSpeedup* s = new CSpeedup(x, y);
					s->m_priority = 90;
					TaskSystem::InsertObj(s);
				}
			}
		}
	}
	else
	{
		;
	}

	//��l����HP���Ȃ��Ȃ�����j��
	if (heart_num == 0)
	{
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	//���_���ڕW���_�ɓ��B������Q�[���N���A
	if (total >= 50)
	{
		Audio::StopLoopMusic(7);
		g_SceneChange = GAMECLEAR;
		is_delete = true;
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(x, y);
}

void CEnemy::Draw()
{
	//�`��
	if (enemy_type == 2)
	{
		//�o
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 3)
	{
		//覐�1
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 10)
	{
		//�G1
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 11)
	{
		//�G2
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 16)
	{
		//�q��
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 17)
	{
		//�\�[���[
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 18)
	{
		//�A���e�i
		Draw::Draw2D(enemy_type, x, y);
	}
	if (enemy_type == 19)
	{
		//覐�2
		Draw::Draw2D(enemy_type, x, y);
	}
}