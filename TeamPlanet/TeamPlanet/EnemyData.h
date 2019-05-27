#pragma once
//使用するヘッダ
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

#pragma once

#include <memory>
using namespace std;

//ユーザー・セーブ・シーン間受け渡しデータクラス
typedef class EnemyData
{
public:
	static void Init(void* data, int size);
	static void Delete();
	static void Open();
	static void Save();
	static void* GetData();

	//ユーザーデータ以外の外部データ読み込み
	//全データ(文字列情報)を取得したメモリが返される
	//テキストエディタでUnicode指定
	static unique_ptr<wchar_t> ExternalDataOpen(wchar_t* file_name, int* size);
private:
	static void* m_data;
	static int   m_data_size;
}Save;

#define ENEMY_NUM 300

struct ENEMYDATA
{
	int enemy_type;	//敵の種類
	int in_time;	//出現時間
	int x;			//X座標
	int y;			//Y座標
	int enemy_speed;//敵のスピード
	int hp;			//HP
	int w;			//W座標
	int h;			//H座標
	int stop_time;	//停止時間
	int out_time;	//帰還時間
	int shot_pattern;//発射パターン
	int shot_time;	//発射時間
	int shot_speed;	//弾のスピード
	int item;		//アイテム
	int point;		//得点
};