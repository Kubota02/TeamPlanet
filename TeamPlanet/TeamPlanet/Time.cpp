//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Time.h"

extern int g_SceneChange;
extern int heart_num;

//コンストラクタ
CTime::CTime()
{
	m_time = 3600;
	Font::CreateStrTex(L"0123456789");
}

//デストラクタ
CTime::~CTime()
{

}

//アクション
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

//ドロー
void CTime::Draw()
{
	int second;
	second = (m_time / 60) % 60;

	if (second < 10)
	{
		swprintf_s(str, L"0%d秒", second);
	}
	else
	{
		swprintf_s(str, L"%d秒", second);
	}
	Font::StrDraw(str, 650.0f, 20.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}