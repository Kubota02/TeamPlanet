//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Gauge.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;

//�R���X�g���N�^
CGauge::CGauge()
{
	//�Q�[�W
	m_x = 480.0f;
	m_y = 20.0f;

	//���[�^�[
	m_x2 = 480.0f;
	m_y2 = 20.0f;

	//�A�j���[�V����
	m_ani_time = 0;
}

//�f�X�g���N�^
CGauge::~CGauge()
{

}

//�A�N�V����
void CGauge::Action()
{
	m_ani_time = total;

	//�n�[�g�������Ȃ������Ɏ��g���폜
	if (heart_num <= 0)
	{
		is_delete = true;
	}

	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 50)
	{
		is_delete = true;
	}
}

//�h���[
void CGauge::Draw()
{
	//�Q�[�W
	Draw::Draw2D(34, m_x - m_ani_time, m_y);

	//���[�^�[
	Draw::Draw2D(31, m_x2, m_y2);
}