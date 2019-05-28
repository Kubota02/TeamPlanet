//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Bullet.h"
#include "Audio.h"
#include "Time.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int heart_num;
extern int total;
extern CTime* g_time;
int h_hp = 100;	//�̗�

CHero::CHero()
{
	//��l���̏����ʒu
	m_x = 0.0f;
	m_y = 250.0f;

	//�����ړ�����
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�e�۔��ː���p
	m_f = true;

	//�̗�
	h_hp = 100;

	//���ʎ��ԗp
	d_time = 0;
	s_time = 0;

	//�A�C�e�����ʂ̐���p
	defense_flag = false;
	time_flag = false;
	heart_flag = false;
	speed_flag = false;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(120.0f, 80.0f);
	m_p_hit_box->SetElement(HERO);		//�����ݒ�
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CHero::~CHero()
{

}

void CHero::Action()
{
	//������
	m_vx = 0.0f;
	m_vy = 0.0f;

	if (d_time != 0)
	{
		d_time++;
	}
	if (s_time != 0)
	{
		s_time++;
	}

	//�e�۔���
	if (Input::KeyPush('L'))
	{
		if (m_f)
		{
			//�e�ۃI�u�W�F�N�g�쐬
			CBullet* bullet = new CBullet(m_x + 125.0f, m_y + 30.0f);
			bullet->m_priority = 90;
			TaskSystem::InsertObj(bullet);
			Audio::StartMusic(0);

			m_f = false;
		}
	}
	else
	{
		m_f = true;
	}

	//�E
	if (Input::KeyPush('D'))
	{
		m_vx += 2.0f;
	}
	//��
	if (Input::KeyPush('A'))
	{
		m_vx -= 2.0f;
	}
	//��
	if (Input::KeyPush('W'))
	{
		m_vy -= 2.0f;
	}
	//��
	if (Input::KeyPush('S'))
	{
		m_vy += 2.0f;
	}

	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = m_vx*m_vx + m_vy*m_vy;
	r = sqrt(r);//r�����[�g�����߂�

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		;
	}
	else
	{
		//���K�����s��
		m_vx = 2.0f / r * m_vx;
		m_vy = 2.0f / r * m_vy;
	}

	//���̕��̂Ɠ����������̏���
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() == ENEMY)
		{
			h_hp += -20;

			//�n�[�g���炷
			if (heart_num > 0)
				heart_num += -1;

			if (h_hp <= 0)
			{
				h_hp = 0;
			}
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == DEFENSE)
		{
			defense_flag = true;
			d_time++;
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == LIFEUP)
		{
			heart_flag = true;
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == TIMEUP)
		{
			time_flag = true;
		}
		if (m_p_hit_box->GetHitData()[i]->GetElement() == SPEEDUP)
		{
			speed_flag = true;
			s_time++;
		}
	  }

	//�̗͂������Ȃ������̍폜����
	if (h_hp == 0)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
		Audio::StopLoopMusic(7);
		Audio::StartMusic(2);
		g_SceneChange = GAMEOVER;
	}

	//�V�[���h
	if (defense_flag)
	{
		m_p_hit_box->SetInvisible(true);
		defense_flag = true;

		if (d_time == 180)
		{
			m_p_hit_box->SetInvisible(false);
			d_time = 0;
			defense_flag = false;
		}
	}
	else
	{
		m_p_hit_box->SetInvisible(false);
		defense_flag = false;
	}

	//�n�[�g�A�C�e������
	if (heart_flag == true)
	{
		if (heart_num == 5)
			;
		else
		{
			heart_num += 1;
			heart_flag = false;
		}
	}

	//�^�C���A�C�e������
	if (time_flag == true)
	{
		CTime* time = (CTime*)TaskSystem::GetObj(TIME);
		time->SetTime();
		time->AddTime(5);
		time_flag = false;
	}

	//�X�s�[�h�A�b�v�A�C�e������
	if (speed_flag == true)
	{
		m_x += m_vx * 2;
		m_y += m_vy * 2;

		speed_flag = true;

		if (s_time == 180)
		{
			//�ړ������Ɉʒu��������
			m_x += m_vx;
			m_y += m_vy;
			s_time = 0;

			speed_flag = false;
		}
	}
	else
	{
		//�ړ������Ɉʒu��������
		m_x += m_vx;
		m_y += m_vy;

		speed_flag = false;
	}

	//�ړ������Ɉʒu��������
	m_x += m_vx;
	m_y += m_vy;

	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 1000)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//�̈�O�ɏo�Ȃ�����
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}
	if (m_x > 800.0f - 120.0f)
	{
		m_x = 680.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_y > 600.0f - 80.0f)
	{
		m_y = 520.0f;
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

void CHero::Draw()
{
	switch (heart_num)
	{
		case 5:
		case 4:
			Draw::Draw2D(0, m_x, m_y);
			break;
		case 3:
		case 2:
			Draw::Draw2D(12, m_x, m_y);
			break;
		case 1:
			Draw::Draw2D(13, m_x, m_y);
			break;
	}
}