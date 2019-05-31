//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Time.h"
#include "Warning.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;
extern int g_time;

//コンストラクタ
CTime::CTime()
{
	m_name = TIME;

	m_x = 400.0f;
	m_y = 20.0f;

	//時間管理用
	m_time = 0;

	//制限時間
	g_time = 200;

	//警告用
	w_time = 57;

	count = 3;

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
	m_time++;

	//1秒ごとに1減らす
	if (m_time == 60)
	{
		g_time--;
		w_time--;
		m_time = 0;
	}

	if (w_time == 0 && count > 0)
	{
		//warningオブジェクト作成
		CWarning* warning = new CWarning();
		warning->m_priority = 90;
		TaskSystem::InsertObj(warning);

		w_time = 60;
		count--;
	}
	
	//ハートが無くなった時に自身を削除
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//時間が無くなったら自身を削除
	if (g_time == 0)
	{
		is_delete = true;
	}

	//得点が目標得点に到達したら自身を削除
	if (total >= 7300)
	{
		is_delete = true;
	}
}

//ドロー
void CTime::Draw()
{
	//時間を文字列に変換
	if (g_time < 10)
	{
		swprintf_s(str, L"0%d", g_time);
	}
	else
	{
		swprintf_s(str, L"%d", g_time);
	}

	//時計の枠組みを描画
	Draw::Draw2D(39, m_x - 14, m_y - 20);

	//表示
	if (g_time >= 100)
	{
		Font::StrDraw(str, m_x, m_y+10, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		Font::StrDraw(str, m_x + 10, m_y + 10, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
}