//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Heartitem.h"

extern int total;

//�R���X�g���N�^
CHeartitem::CHeartitem(float x, float y)
{
	//�ʒu�̏�����
	m_x = x;
	m_y = y;

	//�ړ��x�N�g���̏�����
	m_vx = -3.0f;

	//�q�b�g�{�b�N�X�쐬
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(70.0f, 70.0f);
	m_p_hit_box->SetElement(LIFEUP);   //�����ݒ�
	m_p_hit_box->SetInvisible(false);  //���G���[�h����
}

//�f�X�g���N�^
CHeartitem::~CHeartitem()
{

}

//�A�N�V����
void CHeartitem::Action()
{
	//�ړ�
	m_x += m_vx;

	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (m_x < -50.0f)
	{
		is_delete = true;				//�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
	}

	//�����蔻��̏���
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		//��l���ɓ���������
		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			is_delete = true;				//�I�u�W�F�N�g�̍폜
			m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
		}
	}

	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 6670)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

//�h���[
void CHeartitem::Draw()
{
	Draw::Draw2D(38, m_x, m_y);
}