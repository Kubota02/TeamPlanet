//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"

extern int g_SceneNumber;

CBackground::CBackground()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;
}

CBackground::~CBackground()
{

}

void CBackground::Action()
{
	
}

void CBackground::Draw()
{
	//�`��
	Draw::Draw2D(4, m_x, m_y);
}