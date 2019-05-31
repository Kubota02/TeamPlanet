//STL�f�o�b�N�@�\��OFF�ɂ���
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
	//�w�i�̏����ʒu
	m_x = 0.0f;
	m_y = 0.0f;

	//�F���D�̏����ʒu
	m_x2 = -120.0f;
	m_y2 = 250.0f;

	//�ړ��x�N�g���̏�����
	m_vx = 7.0f;

	m_ani_time = 0;
	key_flag = true;
	time_flag = true;
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
		if (time_flag)
		{
			m_ani_time++;
			time_flag = false;
		}
	}
	else
	{
		time_flag = true;
	}

	if (m_ani_time <= 130)
	{
		m_x2 += m_vx;
	}

	if (m_ani_time >= 130)
	{
		Audio::StartLoopMusic(11);//�o�b�N�~���[�W�b�N�X�^�[�g
		Audio::LoopMusicVolume(11, 0.03f);

		//�����N�Ǘ�
		if (rank_flag == true)
		{
			//�����N����
			CRankM* rankm = new CRankM();
			rankm->m_priority = 70;
			TaskSystem::InsertObj(rankm);

			//�����N��񂾂������p
			rank_flag = false;
		}
	}

	if (m_ani_time >= 270)
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
	Draw::Draw2D(14, m_x2, m_y2);

	//�`��
	if (m_ani_time >= 130)
	{
		Draw::Draw2D(27, m_x, m_y);
	}
}