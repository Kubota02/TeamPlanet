//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Gauge.h"

extern int g_SceneChange;
extern int heart_num;

//�R���X�g���N�^
CGauge::CGauge()
{
	m_x = 480.0f;
	m_y = 20.0f;
}

//�f�X�g���N�^
CGauge::~CGauge()
{

}

//�A�N�V����
void CGauge::Action()
{
	if (heart_num <= 0)
	{
		is_delete = true;
	}
}

//�h���[
void CGauge::Draw()
{
	Draw::Draw2D(34, m_x, m_y);//�Q�[�W
	Draw::Draw2D(31, m_x, m_y);//���[�^�[
}