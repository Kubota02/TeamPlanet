//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Heart.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CHeart::CHeart(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�f�X�g���N�^
CHeart::~CHeart()
{

}

//�A�N�V����
void CHeart::Action()
{

}

//�h���[
void CHeart::Draw()
{
	Draw::Draw2D(15, m_x, m_y);
}