//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Time.h"

extern int g_SceneChange;
extern int heart_num;

//�R���X�g���N�^
CTime::CTime()
{
	m_time = 3600;
	Font::CreateStrTex(L"0123456789");
}

//�f�X�g���N�^
CTime::~CTime()
{

}

//�A�N�V����
void CTime::Action()
{
	m_time--;

	if (heart_num == 0)
	{
		is_delete = true;
	}

	if (m_time == 0)
	{
		is_delete = true;
	}
}

//�h���[
void CTime::Draw()
{
	int second;
	second = (m_time / 60) % 60;

	if (second < 10)
	{
		swprintf_s(str, L"0%d�b", second);
	}
	else
	{
		swprintf_s(str, L"%d�b", second);
	}
	Font::StrDraw(str, 650.0f, 20.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}