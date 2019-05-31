#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//タイトルクラス
class CGameOver :public CObj
{
public:
	CGameOver();
	~CGameOver();
	void Action();
	void Draw();
private:
	float m_x;	//背景位置
	float m_y;

	bool key_flag;  //キーが押されているかチェック用
	bool rank_key_flag; //ランク制御用

	int m_ani_time;//アニメーション
};