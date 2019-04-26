//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Enemybullet.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CEnemybullet::CEnemybullet(float x, float y)
{
	//�G�e�ۂ̏����ʒu
	m_x = x;
	m_y = y;

	//�G�e�ۂ̈ړ��x�N�g��������
	m_vx = 0.0f;

	//�G�e�ۂ̃q�b�g�{�b�N�X�쐬
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 30.0f);
	m_p_hit_box->SetElement(ENEMY);
	m_p_hit_box->SetInvisible(false);
}

//�f�X�g���N�^
CEnemybullet::~CEnemybullet()
{

}

//�A�N�V����
void CEnemybullet::Action()
{
	//���x
	m_vx -= 3.0f;

	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = m_vx*m_vx;
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
	}

	//�ʒu�̍X�V
	m_x += m_vx * 5;

	//�̈�O�ɏo����폜
	if (m_x + 50.0f < 0.0f)
	{
		is_delete = true;              //�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);  //�����蔻��̍폜
	}

	//�G�e�ۂ���l�������Ɠ����������ɍ폜
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_box->GetHitData()[i] == nullptr)
			continue;

		if (m_p_hit_box->GetHitData()[i]->GetElement() == HERO)
		{
			is_delete = true;             //�I�u�W�F�N�g�̍폜
			m_p_hit_box->SetDelete(true); //�����蔻��̍폜
		}
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

//�h���[
void CEnemybullet::Draw()
{
	Draw::Draw2D(11, m_x, m_y);
}