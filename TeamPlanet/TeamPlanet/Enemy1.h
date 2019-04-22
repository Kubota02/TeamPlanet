#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

//敵1クラス
class CEnemy1 : public CObj
{
	public:
		CEnemy1();      //コンストラクタ
		~CEnemy1();     //デストラクタ
		void Action();  //アクション
		void Draw();    //ドロー
	private:
		float m_x;      //位置X
		float m_y;      //位置Y
		float m_vx;     //移動ベクトルX
		float m_vy;     //移動ベクトルY

		int endurance;  //耐久力

		HitBox* m_p_hit_box; //当たり判定
};