//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用ヘッダー
#include "Enemybullet.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CEnemybullet::CEnemybullet(float x, float y)
{
	//敵弾丸の初期位置

}

//デストラクタ
CEnemybullet::~CEnemybullet()
{

}

//アクション
void CEnemybullet::Action()
{

}

//ドロー
void CEnemybullet::Draw()
{
	Draw::Draw2D(11, m_x, m_y);
}