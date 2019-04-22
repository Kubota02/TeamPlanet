//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Enemy1.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CEnemy1::CEnemy1()
{
	//�G1�̏����ʒu
	m_x = rand() % 1100 + 1100;
	m_y = rand() % 600;

	//�����ړ�����
	m_vx = -1.0f;

	//�G1�̏����ϋv��
	endurance = 60;

	//�q�b�g�{�b�N�X�쐬
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(100.0f, 100.0f);
	m_p_hit_box->SetElement(ENEMY1);
	m_p_hit_box->SetInvisible(false);
}

//�f�X�g���N�^
CEnemy1::~CEnemy1()
{

}

//�A�N�V����
void CEnemy1::Action()
{
	//�̈�O�ɏo����I�u�W�F�N�g�j��
	if (m_x < -100.0f)
	{
		is_delete = true;
		m_p_hit_box->SetDelete(true);
	}

	//�ړ������Ɉʒu*���x��������
	m_x += m_vx*2.0f;

	//�����蔻��̏���
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;
		//��l���̒e�ۂɓ���������
		if (m_p_hit_box->GetHitData()[i]->GetElement() == BULLET)
		{
			endurance += -20;
		}
		//��l���ɓ���������
		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			endurance = 0;
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

//�h���[
void CEnemy1::Draw()
{
	//�`��
	Draw::Draw2D(10, m_x, m_y);
}