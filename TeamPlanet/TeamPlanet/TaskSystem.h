#pragma once

//必要ヘッダ
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

//オブジェクトクラス
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

	bool is_delete;				//削除フラグ
	unsigned long m_priority;	//描画優先順位
};

//タスクシステム
typedef class CTaskSystem
{
public:
	CTaskSystem() {}
	~CTaskSystem() {}

	static void InsertObj(CObj* obj);	//追加
	static void ListAction();			//リスト内のアクション実行
	static void ListDraw();				//リスト内のドロー実行

	static void InitTaskSystem();		//初期化
	static void DeleteTaskSystem();		//破棄

	static void SortPriority();			//リスト内のオブジェクトをプライオリティ順にソート
private:
	//リスト CObjを持つオブジェクトの要素を持つ
	static list<shared_ptr<CObj>>*m_task_list;
}TaskSystem;