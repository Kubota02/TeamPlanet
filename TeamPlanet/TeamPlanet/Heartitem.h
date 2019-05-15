#pragma once

//使用ヘッダー
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//ハートアイテムクラス
class CHeartitem : public CObj
{
	public:
		CHeartitem(float x, float y);   //コンストラクタ
		~CHeartitem();                  //デストラクタ
		void Action();                  //アクション
		void Draw();                    //ドロー
	private:
		float m_x;                      //位置X
		float m_y;                      //位置Y
		float m_vx;                     //移動ベクトルX

		HitBox* m_p_hit_box;            //当たり判定
};