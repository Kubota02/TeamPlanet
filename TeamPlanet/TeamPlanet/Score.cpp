//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Score.h"

extern int g_SceneChange;
extern int heart_num;
extern int total;
extern int g_time;

//コンストラクタ
CScore::CScore()
{
	m_x1 = 0.0f;
	m_y1 = 0.0f;

	m_x2 = 670.0f;
	m_y2 = 20.0f;

	//フォント作成用
	Font::CreateStrTex(L"0123456789");
}

//デストラクタ
CScore::~CScore()
{

}

//アクション
void CScore::Action()
{
	//ハートが無くなった時に自身を削除
	if (heart_num == 0)
	{
		is_delete = true;
	}

	//制限時間が無くなった時の削除処理
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
void CScore::Draw()
{
	//描画
	Draw::Draw2D(53, m_x1, m_y1);

	//得点を文字列に変換
	swprintf_s(str, L"%d", total);

	//表示
	if (total >= 0 && total < 1000)
	{
		Font::StrDraw(str, m_x2, m_y2, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		Font::StrDraw(str, m_x2, m_y2, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
}