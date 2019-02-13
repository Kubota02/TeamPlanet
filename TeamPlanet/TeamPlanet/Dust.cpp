//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Dust.h"

CDust::CDust()
{
	//��l���̏����ʒu
	m_x = 800.0f;
	m_y = 200.0f;

	//�����ړ�����
	m_vx = -1.0f;
	//m_vy = -1.0f;

	//HERO�I�u�W�F�N�g�̊e�����蔻��̑������o���o���ɂ���
	static int count = 0;
	count++;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 50.0f);
	m_p_hit_box->SetElement(count);		//������count�ɂ���
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CDust::~CDust()
{

}

void CDust::Action()
{
	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (m_x < 0.0f)
	{
		is_delete = true;				//�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
	}

	//�ړ������Ɉʒu*���x��������
	m_x += m_vx*2.0f;
	//m_y += m_vy*5.0f;

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

void CDust::Draw()
{
	//�`��
	Draw::Draw2D(2, m_x, m_y);
}