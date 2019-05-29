//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameClear.h"
#include "RankM.h"

extern int g_SceneChange;
extern bool g_key_flag;
extern int total;
extern int g_time;

CGameClear::CGameClear()
{
	//背景の初期位置
	m_x = 0.0f;
	m_y = 0.0f;

	m_ani_time = 0;
	key_flag = true;
	
	rank_flag = true;
}

CGameClear::~CGameClear()
{

}

void CGameClear::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	if (total >= 1000)
	{
		if (key_flag)
		{
			m_ani_time++;
			key_flag = false;
		}
	}
	else
	{
		key_flag = true;
	}

	if (g_time == 0)
	{
		if (key_flag)
		{
			m_ani_time++;
			key_flag = false;
		}
	}
	else
	{
		key_flag = true;
	}

	if (m_ani_time >= 100)
	{
		Audio::StartLoopMusic(11);//バックミュージックスタート
		Audio::LoopMusicVolume(11, 0.03f);

		//ランク管理
		if (rank_flag == true)
		{
			//ランク生成
			CRankM* rankm = new CRankM();
			rankm->m_priority = 70;
			TaskSystem::InsertObj(rankm);

			//ランク一回だけ生成用
			rank_flag = false;
		}
	}

	if (m_ani_time >= 240)
	{
		if (Input::KeyPush(VK_RETURN))
		{
			if (g_key_flag)
			{
				total = 0;
				Audio::StopLoopMusic(11);
				g_SceneChange = TITLE;
				g_key_flag = false;
				is_delete = true;
				//
				CRankM* rankm = (CRankM*)TaskSystem::GetObj(RANK);
				rankm->is_delete = true;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
}

void CGameClear::Draw()
{
	//描画
	if (m_ani_time >= 100)
	{
		Draw::Draw2D(27, m_x, m_y);
	}
}