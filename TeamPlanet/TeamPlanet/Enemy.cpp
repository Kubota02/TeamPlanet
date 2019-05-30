//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Enemy.h"
#include "Audio.h"

extern int g_SceneChange;
int total;
extern int heart_num;
extern int g_time;
int boss;

CEnemy::CEnemy(int enemy_type, int in_time, int x, int y, int enemy_speed, int hp,
	int w, int h, int stop_time, int out_time, int shot_pattern, int shot_time, int shot_speed, int item, int point)
{
	//�G�̎��
	this->enemy_type = enemy_type;
	boss = enemy_type;

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
}

CEnemy::~CEnemy()
{

}

void CEnemy::Action()
{
	m_count++;

	if (x >= 800)
	{
		m_p_hit_box->SetInvisible(true);	//���G���[�h
	}
	else
	{
		//���̓����蔻��
		if (enemy_type == 5)
		{
			m_p_hit_box->SetPos(x + 20, y + 25);
			m_p_hit_box->SetWH(w - 260, h - 75);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�y���̓����蔻��
		else if (enemy_type == 6)
		{
			m_p_hit_box->SetPos(x + 120, y + 40);
			m_p_hit_box->SetWH(w - 270, h - 75);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�V�����̓����蔻��
		else if (enemy_type == 7)
		{
			m_p_hit_box->SetPos(x + 30, y + 110);
			m_p_hit_box->SetWH(w - 240, h - 65);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�o�̓����蔻��
		else if (enemy_type == 2)
		{
			m_p_hit_box->SetPos(x + 10, y + 10);
			m_p_hit_box->SetWH(w -15, h - 15);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//覐�1�̓����蔻��
		else if (enemy_type == 3)
		{
			m_p_hit_box->SetPos(x + 17, y + 23);
			m_p_hit_box->SetWH(w - 25, h - 36);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�q���̓����蔻��
		else if (enemy_type == 16)
		{
			m_p_hit_box->SetPos(x + 17, y + 30);
			m_p_hit_box->SetWH(w - 45, h - 70);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}

		//�\�[���[�̓����蔻��
		else if (enemy_type == 17)
		{
			m_p_hit_box->SetPos(x + 8, y + 10);
			m_p_hit_box->SetWH(w - 30, h - 30);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�A���e�i�̓����蔻��
		else if (enemy_type == 18)
		{
			m_p_hit_box->SetPos(x + 9, y + 7);
			m_p_hit_box->SetWH(w - 12, h - 8);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//覐�2�̓����蔻��
		else if (enemy_type == 19)
		{
			m_p_hit_box->SetPos(x + 25, y + 27);
			m_p_hit_box->SetWH(w - 45, h - 40);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�G1�̓����蔻��
		else if (enemy_type == 10)
		{
			m_p_hit_box->SetPos(x + 15, y + 30);
			m_p_hit_box->SetWH(w - 25, h - 50);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		//�G2�̓����蔻��
		else if (enemy_type == 11)
		{
			m_p_hit_box->SetPos(x + 10, y + 30);
			m_p_hit_box->SetWH(w - 15, h - 45);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
		else
		{
			//�����蔻��
			m_p_hit_box->SetPos(x, y);
			m_p_hit_box->SetWH(w, h);
			m_p_hit_box->SetElement(ENEMY);	//�����ݒ�
			m_p_hit_box->SetInvisible(false);	//���G���[�h����
		}
	}

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
			//BossBGM�X�^�[�g
			Audio::StopLoopMusic(7);
			Audio::StartLoopMusic(4);
			Audio::LoopMusicVolume(4, 0.03f);

			//�ړ������Ɉʒu*���x��������
			x += m_vx*enemy_speed;
		}
		else if (out_time < m_count)
		{
			x -= m_vx*enemy_speed;

			if (x > 800)
			{
				//�{�X�~���[�W�b�N�~�߂�
				Audio::StopLoopMusic(4);
				Audio::StartLoopMusic(7);
				Audio::LoopMusicVolume(7, 0.03f);
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
			if (enemy_type != 5 && enemy_type != 6 && enemy_type != 7)
			{
				hp = 0;
			}
			else
			{
				;
			}
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

			if (enemy_type != 5 && enemy_type != 6 && enemy_type != 7)
			{
				;
			}
			else
			{
				Audio::StopLoopMusic(4);
				Audio::StartLoopMusic(7);
				Audio::LoopMusicVolume(7, 0.03f);
			}
			
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

				//else if (item == 4 && m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
				//{
				//	//�^�C���A�C�e���I�u�W�F�N�g�쐬
				//	CTimeitem* t = new CTimeitem(x, y);
				//	t->m_priority = 90;
				//	TaskSystem::InsertObj(t);
				//}
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

	//�������Ԃ������Ȃ������̍폜����
	if (g_time == 0)
	{
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	//���_���ڕW���_�ɓ��B������Q�[���N���A
	if (total >= 6670)
	{
		Audio::StopLoopMusic(7);
		g_SceneChange = GAMECLEAR;
		m_p_hit_box->SetDelete(true);
		is_delete = true;
	}

	if (enemy_type == 5)
	{
		//���̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 20, y + 25);
	}
	else if (enemy_type == 6)
	{
		//�y���̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 120, y + 40);
	}
	else if (enemy_type == 7)
	{
		//�V�����̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 30, y + 110);
	}
	else if (enemy_type == 2)
	{
		//�o�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 10, y + 10);
	}
	else if (enemy_type == 3)
	{
		//覐�1�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 17, y + 23);
	}
	else if (enemy_type == 16)
	{
		//�q���̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 17, y + 30);
	}
	else if (enemy_type == 17)
	{
		//�\�[���[�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 8, y + 10);
	}
	else if (enemy_type == 18)
	{
		//�A���e�i�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 9, y + 7);
	}
	else if (enemy_type == 19)
	{
		//覐�2�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 25, y + 27);
	}
	else if (enemy_type == 10)
	{
		//�G1�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 15, y + 30);
	}
	else if (enemy_type == 11)
	{
		//�G2�̓����蔻��̈ʒu�X�V
		m_p_hit_box->SetPos(x + 10, y + 30);
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
		return;
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