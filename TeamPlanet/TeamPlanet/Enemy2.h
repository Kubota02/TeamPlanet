#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

//敵2クラス
class CEnemy2 : public CObj
{
	public:
		CEnemy2();       //コンストラクタ
		~CEnemy2();      //デストラクタ
		void Action();   //アクション
		void Draw();     //ドロー
	private:
		float m_x;       //位置X
		float m_y;       //位置Y
		float m_vx;      //移動ベクトルX
		float m_vy;      //移動ベクトルY

		int endurance;   //耐久力

		HitBox* m_p_hit_box; //当たり判定
};