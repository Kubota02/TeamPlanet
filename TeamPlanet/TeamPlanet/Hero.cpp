//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

CHero::CHero()
{
	//�����_���ŏ����l�����߂�
	/*m_x = rand() % 300 + 100;
	m_y = rand() % 300 + 100;*/

	//��l���̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;

	//�����ړ�����
	m_vx = 0.0f;
	m_vy = 0.0f;

	//HERO�I�u�W�F�N�g�̊e�����蔻��̑������o���o���ɂ���
	static int count = 0;
	count++;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(120.0f, 80.0f);
	m_p_hit_box->SetElement(count);		//������count�ɂ���
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CHero::~CHero()
{

}

void CHero::Action()
{
	//�E
	if (Input::KeyPush(VK_RIGHT))
	{
		m_x += 3.0f;
	}
	//��
	if (Input::KeyPush(VK_LEFT))
	{
		m_x -= 3.0f;
	}
	//��
	if (Input::KeyPush(VK_UP))
	{
		m_y -= 3.0f;
	}
	//��
	if (Input::KeyPush(VK_DOWN))
	{
		m_y += 3.0f;
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

	//�폜���s
	//if (Input::KeyPush('Z'))
	//{
	//	is_delete = true;				//�I�u�W�F�N�g�̍폜
	//	m_p_hit_box->SetDelete(true);	//�����蔻��̍폜
	//}

	//�̈�ɏo�Ȃ��悤�ɔ��˂�����
	/*if (m_x <			 0.0f) m_vx = +1.0f;
	if (m_x > 800.0f - 256.0f) m_vx = -1.0f;
	if (m_y <			 0.0f) m_vy = +1.0f;
	if (m_y > 600.0f - 256.0f) m_vy = -1.0f;*/

	//�ړ������Ɉʒu*���x��������
	/*m_x += m_vx*5.0f;
	m_y += m_vy*5.0f;*/
}

void CHero::Draw()
{
	//�`��
	Draw::Draw2D(0, m_x, m_y);
}