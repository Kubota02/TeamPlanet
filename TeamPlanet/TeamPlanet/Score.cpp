//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Score.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;
extern int g_time;

//�R���X�g���N�^
CScore::CScore()
{
	m_x1 = 600.0f;
	m_y1 = 50.0f;

	m_x2 = 650.0f;
	m_y2 = 50.0f;

	//�t�H���g�쐬�p
	Font::CreateStrTex(L"0123456789");
}

//�f�X�g���N�^
CScore::~CScore()
{

}

//�A�N�V����
void CScore::Action()
{
	//�n�[�g�������Ȃ������Ɏ��g���폜
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//�������Ԃ������Ȃ������̍폜����
	if (g_time == 0)
	{
		is_delete = true;
	}

	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 6670)
	{
		is_delete = true;
	}

	//total�Ⴗ������GAMEOVER
	/*if (g_time == 0 && (total >= 0 && total < 1000))
	{
		g_SceneChange = GAMEOVER;
	}*/
}

//�h���[
void CScore::Draw()
{
	if (total >= 0 && total < 1000)
	{
		swprintf_s(str, L"0%d", total);
	}
	else
	{
		swprintf_s(str, L"%d", total);
	}

	//Draw::Draw2D(31, m_x1, m_y1); //�摜

	Font::StrDraw(str, m_x2, m_y2, 1.0f,1.0f, 1.0f, 1.0f, 1.0f);

}