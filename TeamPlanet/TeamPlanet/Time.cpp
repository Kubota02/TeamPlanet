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
	//制限時間の初期化
	m_time = 3600;

	//フォント作成用
	Font::CreateStrTex(L"0123456789");
}

//デストラクタ
CTime::~CTime()
{

}

//アクション
void CTime::Action()
{
	//時間を減らしていく
	m_time--;

	//ハートが無くなった時に自身を削除
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//時間が無くなったら自身を削除
	if (m_time == 0)
	{
		is_delete = true;
	}
}

//ドロー
void CTime::Draw()
{
	int second;//秒
	second = (m_time / 60) % 60;//60フレームで一秒

	if (second < 10)
	{
		swprintf_s(str, L"残り0%d秒", second);
	}
	else
	{
		swprintf_s(str, L"残り%d秒", second);
	}

	//フォント描画
	Font::StrDraw(str, 650.0f, 20.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}