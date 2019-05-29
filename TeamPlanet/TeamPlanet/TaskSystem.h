#pragma once

//必要ヘッダ
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

	unsigned int GetName() { return m_name; };

	unsigned int m_name;//オブジェクトの名前

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

	static CObj* GetObj(unsigned int n);

	static void InitTaskSystem();		//初期化
	static void DeleteTaskSystem();		//破棄

	static void SortPriority();			//リスト内のオブジェクトをプライオリティ順にソート
private:
	//リスト CObjを持つオブジェクトの要素を持つ
	static list<shared_ptr<CObj>>*m_task_list;
}TaskSystem;