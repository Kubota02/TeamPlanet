//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "HeroBoom.h"

extern bool g_key_flag;
extern int h_hp;
extern int g_SceneChange;

//�R���X�g���N�^
CHeroBoom::CHeroBoom(float x, float y)
{
	m_x = x;
	m_y = y;

	m_ani_time = 0;
}

//�f�X�g���N�^
CHeroBoom::~CHeroBoom()
{

}

//�A�N�V����
void CHeroBoom::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	//��l����HP��0�ɂȂ����Ƃ�
	if (h_hp == 0)
	{
		if (g_key_flag)
		{
			m_ani_time++;
			g_key_flag = false;
		}
	}
	else
	{
		g_key_flag = true;
	}
	
	if (m_ani_time >= 80)
	{
		is_delete = true;
		g_SceneChange = GAMEOVER;
	}
}

//�h���[
void CHeroBoom::Draw()
{
	//�`��
	Draw::Draw2D(21, m_x, m_y);
}