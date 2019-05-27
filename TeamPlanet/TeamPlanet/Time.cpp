//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p�w�b�_�[
#include "Time.h"
#include "Warning.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;
//extern int g_time;

//�R���X�g���N�^
CTime::CTime()
{
	m_name = TIME;

	m_x = 400.0f;
	m_y = 20.0f;

	//���ԊǗ��p
	m_time = 0;

	//�c�莞��
	time = 180;

	w_time = 57;

	count = 3;

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
	//m_time--;

	m_time++;

	//1�b���Ƃ�1���炷
	if (m_time == 60)
	{
		time--;
		w_time--;
		m_time = 0;
	}

	if (w_time == 0 && count > 0)
	{
		//warning�I�u�W�F�N�g�쐬
		CWarning* warning = new CWarning();
		warning->m_priority = 90;
		TaskSystem::InsertObj(warning);

		w_time = 57;
		count--;
	}
	
	//�n�[�g�������Ȃ������Ɏ��g���폜
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//���Ԃ������Ȃ����玩�g���폜
	if (time == 0)
	{
		is_delete = true;
	}

	//���_���ڕW���_�ɓ��B�����玩�g���폜
	if (total >= 1000)
	{
		is_delete = true;
	}
}

//�h���[
void CTime::Draw()
{
	if (time < 10)
	{
		swprintf_s(str, L"0%d", time);
	}
	else
	{
		swprintf_s(str, L"%d", time);
	}

	Draw::Draw2D(39, m_x - 14, m_y - 20);

	if (time >= 100)
	{
		Font::StrDraw(str, m_x, m_y+10, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		Font::StrDraw(str, m_x + 10, m_y + 10, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
}