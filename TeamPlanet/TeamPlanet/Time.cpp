//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Time.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;

//�R���X�g���N�^
CTime::CTime()
{
	m_name = TIME;

	m_x = 400.0f;
	m_y = 20.0f;

	//�������Ԃ̏�����
	m_time = 3600;

	add_time = 3;

	//�t�H���g�쐬�p
	Font::CreateStrTex(L"0123456789");
}

//�f�X�g���N�^
CTime::~CTime()
{

}

//�A�N�V����
void CTime::Action()
{
	//���Ԃ����炵�Ă���
	m_time--;

	//second = (m_time / 60) % 60;//60�t���[���ň�b

	//�n�[�g�������Ȃ������Ɏ��g���폜
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//���Ԃ������Ȃ����玩�g���폜
	if (second == 0)
	{
		is_delete = true;
	}

	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 50)
	{
		is_delete = true;
	}
}

//�h���[
void CTime::Draw()
{
	second = (m_time / 60) % 60;//60�t���[���ň�b

	if (second < 10)
	{
		swprintf_s(str, L"0%d", second);
	}
	else
	{
		swprintf_s(str, L"%d", second);
	}
	Draw::Draw2D(39, m_x-14, m_y-20);
	//�t�H���g�`��
	Font::StrDraw(str, m_x, m_y+13, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}