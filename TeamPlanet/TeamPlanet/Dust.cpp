//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Dust.h"

extern int g_SceneNumber;
extern bool g_key_flag;

CDust::CDust()
{
	//�o�̏����ʒu
	//m_x = 850.0f;
	//m_y = 200.0f;
	m_x = rand() % 1100 + 1100;
	m_y = rand() % 600;

	//�����ړ�����
	m_vx = -1.0f;

	//�o�̏����ϋv
	endurance = 40;

	//Dust�I�u�W�F�N�g�̊e�����蔻��̑������o���o���ɂ���
	static int count = 0;
	count++;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 50.0f);
	m_p_hit_box->SetElement(DUST);		//�����ݒ�
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CDust::~CDust()
{

}

void CDust::Action()
{
	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (m_x < -50.0f)
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

void CDust::Draw()
{
	//�`��
	Draw::Draw2D(2, m_x, m_y);
}