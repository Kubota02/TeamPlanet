#pragma once
//�g�p����w�b�_
#include "Draw2DPolygon.h"
#include "TaskSystem.h"
#include "Collision.h"

#pragma once

#include <memory>
using namespace std;

//���[�U�[�E�Z�[�u�E�V�[���Ԏ󂯓n���f�[�^�N���X
typedef class EnemyData
{
public:
	static void Init(void* data, int size);
	static void Delete();
	static void Open();
	static void Save();
	static void* GetData();

	//���[�U�[�f�[�^�ȊO�̊O���f�[�^�ǂݍ���
	//�S�f�[�^(��������)���擾�������������Ԃ����
	//�e�L�X�g�G�f�B�^��Unicode�w��
	static unique_ptr<wchar_t> ExternalDataOpen(wchar_t* file_name, int* size);
private:
	static void* m_data;
	static int   m_data_size;
}Save;

#define ENEMY_NUM 300

struct ENEMYDATA
{
	int enemy_type;	//�G�̎��
	int in_time;	//�o������
	int x;			//X���W
	int y;			//Y���W
	int enemy_speed;//�G�̃X�s�[�h
	int hp;			//HP
	int w;			//W���W
	int h;			//H���W
	int stop_time;	//��~����
	int out_time;	//�A�Ҏ���
	int shot_pattern;//���˃p�^�[��
	int shot_time;	//���ˎ���
	int shot_speed;	//�e�̃X�s�[�h
	int item;		//�A�C�e��
	int point;		//���_
};