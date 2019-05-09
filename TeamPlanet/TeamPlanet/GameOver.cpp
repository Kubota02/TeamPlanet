//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameOver.h"

extern int g_SceneChange;
extern bool g_key_flag;

CGameOver::CGameOver()
{
	//背景の初期位置
	m_x = 0.0f;
	m_y = 0.0f;
}

CGameOver::~CGameOver()
{

}

void CGameOver::Action()
{
	//Audio::StartLoopMusic(10);//バックミュージックスタート
	//Audio::LoopMusicVolume(10, 0.03f);
}

void CGameOver::Draw()
{
	//描画
	Draw::Draw2D(28, m_x, m_y);
}