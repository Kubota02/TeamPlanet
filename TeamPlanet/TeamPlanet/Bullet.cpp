//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Bullet.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CBullet::CBullet(float x,float y)
{
	//�e�ۂ̏����ʒu
	m_x = x;
	m_y = y;

	//�e�ۂ̈ړ��x�N�g��������
	m_vx = 0.0f;

	//�e�ۂ̃_���[�W�ʏ�����
	m_damage = 20;

	//�q�b�g�{�b�N�X�쐬
	m_p_hit_box = Collision::HitBoxInsert(this);

	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(50.0f, 30.0f);
	m_p_hit_box->SetElement(BULLET);   //�����ݒ�
	m_p_hit_box->SetInvisible(false);  //���G���[�h����
}

//�f�X�g���N�^
CBullet::~CBullet()
{

}

//�A�N�V����
void CBullet::Action()
{
	//���x
	m_vx += 3.0f;

	//�ʒu�̍X�V
	m_x += m_vx;

	//�̈�O�ɏo����폜
	if (m_x > 800.0f - 50.0f)
	{
		is_delete = true;              //�I�u�W�F�N�g�̍폜
		m_p_hit_box->SetDelete(true);  //�����蔻��̍폜
	}

	//�e�ۂ����̕��̂Ɠ����������ɍ폜
	if (1)
	{
		/*is_delete = true;
		m_p_hit_box->SetDelete(true);*/
	}

	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

//�h���[
void CBullet::Draw()
{
	Draw::Draw2D(1, m_x, m_y);
}