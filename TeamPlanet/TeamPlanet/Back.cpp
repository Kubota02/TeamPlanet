//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Back.h"

CBack::CBack()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;
}

CBack::~CBack()
{

}

void CBack::Action()
{

}

void CBack::Draw()
{
	//�`��
	Draw::Draw2D(42, m_x, m_y);
}