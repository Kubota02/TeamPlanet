//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Enemybullet.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CEnemybullet::CEnemybullet(float x, float y)
{
	//�G�e�ۂ̏����ʒu

}

//�f�X�g���N�^
CEnemybullet::~CEnemybullet()
{

}

//�A�N�V����
void CEnemybullet::Action()
{

}

//�h���[
void CEnemybullet::Draw()
{
	Draw::Draw2D(11, m_x, m_y);
}