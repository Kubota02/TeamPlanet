#pragma once

//�K�v�w�b�_
#include <memory>
#include <list>

using namespace std;

enum SceneChange
{
	TITLE				 = 0,
	TITLE_MAIN			 = 1,
	DESCRIPTION			 = 2,
	DESCRIPTION_MAIN	 = 3,
	/*STAGESELECT			 = 4,
	STAGESELECT_MAIN	 = 5,*/
	GAME				 = 4,
	GAME_MAIN			 = 5,
	GAMEOVER			 = 6,
	GAMEOVER_MAIN		 = 7,
	GAMECLEAR			 = 8,
	GAMECLEAR_MAIN		 = 9,
	//RESULT			 = 12,
	//RESULT_MAIN		 = 13,
	ALLCLEAR			 = 10,
	ALLCLEAR_MAIN		 = 11,
};

enum 
{
	LEFT,
	RIGHT,
	UNDER,
};

enum {
	STAGE1,
	STAGE2,
	STAGE3,
};

enum
{
	HERO = 0,
	BULLET = 1,
	ENEMY = 2,
	ENEMYBULLET = 3,
	DEFENSE = 4,
	LIFEUP = 5,
	TIMEUP = 6,
	TIME = 7,
	SPEEDUP = 8,
	WARNING = 9,
	RANK = 10,
};

//�I�u�W�F�N�g�N���X
class CObj
{
public:
	CObj() 
	{
		is_delete = false;
		m_priority = 0;
	};

	virtual ~CObj() {};
	virtual void Action() = 0;
	virtual void Draw() = 0;

	unsigned int GetName() { return m_name; };

	unsigned int m_name;//�I�u�W�F�N�g�̖��O

	bool is_delete;				//�폜�t���O
	unsigned long m_priority;	//�`��D�揇��
};

//�^�X�N�V�X�e��
typedef class CTaskSystem
{
public:
	CTaskSystem() {}
	~CTaskSystem() {}

	static void InsertObj(CObj* obj);	//�ǉ�
	static void ListAction();			//���X�g���̃A�N�V�������s
	static void ListDraw();				//���X�g���̃h���[���s

	static CObj* GetObj(unsigned int n);

	static void InitTaskSystem();		//������
	static void DeleteTaskSystem();		//�j��

	static void SortPriority();			//���X�g���̃I�u�W�F�N�g���v���C�I���e�B���Ƀ\�[�g
private:
	//���X�g CObj�����I�u�W�F�N�g�̗v�f������
	static list<shared_ptr<CObj>>*m_task_list;
}TaskSystem;