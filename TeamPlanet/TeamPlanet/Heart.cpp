//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Heart.h"

extern int heart_num;

//�R���X�g���N�^
CHeart::CHeart()
{
	
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
	//Draw::Draw2D(15, m_x, m_y);
	for (int i = 0; i < heart_num; i++)
	{
		Draw::Draw2D(15, i*60.0f, 5.0f);
	}
}