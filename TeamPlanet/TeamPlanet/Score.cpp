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
	m_x1 = 600.0f;
	m_y1 = 50.0f;

	m_x2 = 650.0f;
	m_y2 = 50.0f;

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
	if (total >= 6670)
	{
		is_delete = true;
	}

	//total低すぎた時GAMEOVER
	/*if (g_time == 0 && (total >= 0 && total < 1000))
	{
		g_SceneChange = GAMEOVER;
	}*/
}

//ドロー
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

	//Draw::Draw2D(31, m_x1, m_y1); //画像

	Font::StrDraw(str, m_x2, m_y2, 1.0f,1.0f, 1.0f, 1.0f, 1.0f);

}