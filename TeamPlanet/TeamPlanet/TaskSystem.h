#pragma once

//�K�v�w�b�_
#include <memory>
#include <list>

using namespace std;

enum SceneChange
{
	//TITLE				 = 0,
	//TITLE_MAIN			 = 1,
	STAGESELECT		 = 2,
	STAGESELECT_MAIN	 = 3,
	//STORY				 = 4,
	//STORY_MAIN			 = 5,
	GAME				 = 6,
	GAME_MAIN			 = 7,
	//GAME2				 = 8,
	//GAME_MAIN2			 = 9,
	//GAME3				 = 10,
	//GAME_MAIN3			 = 11,
	//RESULT				 = 12,
	//RESULT_MAIN			 = 13,
	//ALLCLEAR			 = 14,
	//ALLCLEAR_MAIN		 = 15,
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
	DUST = 2,
	METEORITE = 3,
	ENEMY1 = 4,
	ENEMY2 = 5,
	ENEMYBULLET = 6,
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

	static void InitTaskSystem();		//������
	static void DeleteTaskSystem();		//�j��

	static void SortPriority();			//���X�g���̃I�u�W�F�N�g���v���C�I���e�B���Ƀ\�[�g
private:
	//���X�g CObj�����I�u�W�F�N�g�̗v�f������
	static list<shared_ptr<CObj>>*m_task_list;
}TaskSystem;