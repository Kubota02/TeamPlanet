//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Back.h"

CBack::CBack()
{
	//�w�i�̏����ʒu
	m_x1 = 0.0f;
	m_x2 = 1000.0f;
	m_y = 0.0f;
}

CBack::~CBack()
{

}

void CBack::Action()
{
	//�w�i1
	m_x1 -= 0.6f;
	if (m_x1 < -990.0f)
	{
		m_x1 = 980.0f;
	}

	//�w�i2
	m_x2 -= 0.6f;
	if (m_x2 < -990.0f)
	{
		m_x2 = 980.0f;
	}
}

void CBack::Draw()
{
	//�`��
	Draw::Draw2D(42, m_x1, m_y);//�w�i1
	Draw::Draw2D(42, m_x2, m_y);//�w�i2
}