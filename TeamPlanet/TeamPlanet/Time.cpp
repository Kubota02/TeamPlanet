//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Time.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;

//コンストラクタ
CTime::CTime()
{
	m_name = TIME;

	m_x = 400.0f;
	m_y = 20.0f;

	//制限時間の初期化
	m_time = 3600;

	add_time = 3;

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

	//second = (m_time / 60) % 60;//60フレームで一秒

	//ハートが無くなった時に自身を削除
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//時間が無くなったら自身を削除
	if (second == 0)
	{
		is_delete = true;
	}

	//得点が目標得点に到達したら自身を削除
	if (total >= 50)
	{
		is_delete = true;
	}
}

//ドロー
void CTime::Draw()
{
	second = (m_time / 60) % 60;//60フレームで一秒

	if (second < 10)
	{
		swprintf_s(str, L"0%d", second);
	}
	else
	{
		swprintf_s(str, L"%d", second);
	}
	Draw::Draw2D(39, m_x-14, m_y-20);
	//フォント描画
	Font::StrDraw(str, m_x, m_y+13, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}