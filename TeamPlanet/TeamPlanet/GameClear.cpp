//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameClear.h"

extern int g_SceneChange;
extern bool g_key_flag;

CGameClear::CGameClear()
{
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;
}

CGameClear::~CGameClear()
{

}

void CGameClear::Action()
{

}

void CGameClear::Draw()
{
	//�`��
	Draw::Draw2D(27, m_x, m_y);
}