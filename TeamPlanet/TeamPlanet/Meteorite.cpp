//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Meteorite.h"

extern int g_SceneNumber;
extern bool g_key_flag;

CMeteorite::CMeteorite()
{
	//覐΂̏����ʒu
	//m_x = 800.0f;
	//m_y = 300.0f;

	m_x = rand() % 1000 + 1000;
	m_y = rand() % 500;

	//�����ړ�����
	m_vx = -1.0f;

	//覐΂̏����ϋv
	endurance = 60;

	//Meteorite�I�u�W�F�N�g�̊e�����蔻��̑������o���o���ɂ���
	static int count = 0;
	count++;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(100.0f, 100.0f);
	m_p_hit_box->SetElement(METEORITE);	//�����ݒ�
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CMeteorite::~CMeteorite()
{

}

void CMeteorite::Action()
{
	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (m_x < -100.0f)
	{
		is_delete = true;				//�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
	}

	//�ړ������Ɉʒu*���x��������
	m_x += m_vx*2.0f;

	//�e�ۂɓ����������̃_���[�W����
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		if (m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			/*is_delete = true;
			m_p_hit_box->SetDelete(true);*/
			endurance += -20;
		}
	}

	//�ϋv�͂������Ȃ������̍폜����
	if (endurance == 0)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

void CMeteorite::Draw()
{
	//�`��
	Draw::Draw2D(3, m_x, m_y);
}