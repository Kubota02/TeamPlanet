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

	//�o���J�E���g
	m_count = 0;

	//�����ړ�����
	m_vx = -1.0f;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	if (enemy_type == 6)
	{
		m_p_hit_box->SetPos(x + 100, y - 10);
		m_p_hit_box->SetWH(w - 200, h - 10);
		m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
		m_p_hit_box->SetInvisible(false);	//���G���[�h����
	}
	else
	{
		m_p_hit_box->SetPos(x, y);
		m_p_hit_box->SetWH(w, h);
		m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
		m_p_hit_box->SetInvisible(false);	//���G���[�h����
	}
}

CEnemy::~CEnemy()
{

}

void CEnemy::Action()
{
	m_count++;

	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (x < -100.0f)
	{
		is_delete = true;				//�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
	}

	//enemy_type��5,6,7�ȊO�Ȃ炻�̂܂�
	if (enemy_type != 5 && enemy_type != 6 && enemy_type != 7)
	{
		if (in_time < m_count)
		{
			//�ړ������Ɉʒu*���x��������
			x += m_vx*enemy_speed;
		}
	}
	else
	{
		if (in_time < m_count && m_count < stop_time)
		{
			//�ړ������Ɉʒu*���x��������
			x += m_vx*enemy_speed;
		}
		else if (out_time < m_count)
		{
			x -= m_vx*enemy_speed;

			if (x > 1000)
			{
				is_delete = true;				//�I�u�W�F�N�g�̍폜
				m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
			}
		}
	}

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
			//����������邩�Ȃ��H

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
					//�X�s�[�h�A�b�v�A�C�e���I�u�W�F�N�g�쐬
					CSpeedup* s = new CSpeedup(x, y);
					s->m_priority = 90;
					TaskSystem::InsertObj(s);
				}

				else if (item == 3 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//�n�[�g�A�C�e���I�u�W�F�N�g�쐬
					CHeartitem* h = new CHeartitem(x, y);
					h->m_priority = 90;
					TaskSystem::InsertObj(h);
				}

				else if (item == 4 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				{
					//�^�C���A�C�e���I�u�W�F�N�g�쐬
					CTimeitem* t = new CTimeitem(x, y);
					t->m_priority = 90;
					TaskSystem::InsertObj(t);
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
	if (total >= 1000)
	{
		Audio::StopLoopMusic(7);
		g_SceneChange = GAMECLEAR;
		is_delete = true;
	}

	if (enemy_type == 6)
	{
		//�����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 100, y + 10);
	}
	else
	{
		//�����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x, y);
	}
}

void CEnemy::Draw()
{
	if (x >= 800)
	{
		;
	}
	else
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
		if (enemy_type == 5)
		{
			//��
			Draw::Draw2D(enemy_type, x, y);
		}
		if (enemy_type == 6)
		{
			//�y��
			Draw::Draw2D(enemy_type, x, y);
		}
		if (enemy_type == 7)
		{
			//�V����
			Draw::Draw2D(enemy_type, x, y);
		}
	}
}