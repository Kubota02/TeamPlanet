#pragma once

//使用ヘッダー
#include "Draw2DPolygon.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "Collision.h"

//弾丸クラス
class CBullet : public CObj
{
	public:
		CBullet(float x,float y);     //コンストラクタ
		~CBullet();                   //デストラクタ
		void Action();                //アクション
		void Draw();                  //ドロー
	private:
		float m_x;                    //弾丸の位置X
		float m_y;                    //弾丸の位置Y
		float m_vx;                   //移動ベクトルX

		int m_damage;                 //弾丸のダメージ量

		int m_ani_time;               //アニメーションタイム

		HitBox* m_p_hit_box;          //当たり判定
};