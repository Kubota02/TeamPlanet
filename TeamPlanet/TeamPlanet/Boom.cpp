//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Boom.h"

//�R���X�g���N�^
CBoom::CBoom(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�f�X�g���N�^
CBoom::~CBoom()
{

}

//�A�N�V����
void CBoom::Action()
{

}

//�h���[
void CBoom::Draw()
{
	Draw::Draw2D(21, m_x, m_y);
}