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
	m_x1 = 0.0f;
	m_y1 = 0.0f;

	m_x2 = 670.0f;
	m_y2 = 20.0f;

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
	if (total >= 7300)
	{
		is_delete = true;
	}
}

//�h���[
void CScore::Draw()
{
	//�`��
	Draw::Draw2D(53, m_x1, m_y1);

	//���_�𕶎���ɕϊ�
	swprintf_s(str, L"%d", total);

	//�\��
	if (total >= 0 && total < 1000)
	{
		Font::StrDraw(str, m_x2, m_y2, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		Font::StrDraw(str, m_x2, m_y2, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
}