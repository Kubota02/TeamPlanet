//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Bullet.h"
#include "Audio.h"

extern int g_SceneChange;
extern bool g_key_flag;

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
	m_hp = 100;

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
	////�̗͕\��
	//for (int i = 0; i < 5; i++)
	//{
	//	heart = new CHeart(i*60.0f, 5.0f);
	//	heart->m_priority = 90;
	//	TaskSystem::InsertObj(heart);
	//}

	//�e�۔���
	if (Input::KeyPush(VK_SPACE))
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

	//������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�E
	if (Input::KeyPush(VK_RIGHT))
	{
		m_vx += 3.0f;
	}
	//��
	if (Input::KeyPush(VK_LEFT))
	{
		m_vx -= 3.0f;
	}
	//��
	if (Input::KeyPush(VK_UP))
	{
		m_vy -= 3.0f;
	}
	//��
	if (Input::KeyPush(VK_DOWN))
	{
		m_vy += 3.0f;
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
		m_vx = 3.0f / r * m_vx;
		m_vy = 3.0f / r * m_vy;
	}

	//�ړ������Ɉʒu��������
	m_x += m_vx;
	m_y += m_vy;

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

	//���̕��̂Ɠ����������̏���
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() != HERO)
		{
			m_hp += -20;

			//�n�[�g���炷
			;
		}
	  }

	//�̗͂������Ȃ������̍폜����
	if (m_hp <= 0)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
		g_SceneChange = GAMEOVER;
		is_delete = true;
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

void CHero::Draw()
{
	Draw::Draw2D(0, m_x, m_y);
	//Draw::Draw2D(20, m_x + 200.0f, m_y);
}