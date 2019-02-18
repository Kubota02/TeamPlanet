#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//ゲームセレクトクラス
class CSelect :public CObj
{
public:
	CSelect();
	~CSelect();
	void Action();
	void Draw();
private:
	float m_x;	//位置
	float m_y;
	unsigned int m_cursor; //カーソル位置
	unsigned int m_BefCursor; //前のカーソル位置
	bool key_flag;  //キーが押されているかチェック用
	int m_ani_time;//アイコン変更アニメーション
};