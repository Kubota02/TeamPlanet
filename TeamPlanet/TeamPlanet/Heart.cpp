//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Heart.h"

extern int heart_num;
extern int total;

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
	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 1000)
	{
		is_delete = true;
	}
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