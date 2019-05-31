//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include <stdio.h>
#include <locale.h>

#include "EnemyData.h"

using namespace std;

#define SAVE_NAME (L"enemy_data")

void* EnemyData::m_data;		//�G���
int   EnemyData::m_data_size;	//�G���T�C�Y

ENEMYDATA e_data[ENEMY_NUM];	//�G�̃f�[�^

void* EnemyData::GetData()
{
	return m_data;
}

void EnemyData::Init(void *data, int size)
{
	setlocale(LC_CTYPE, "jpn");
	m_data = data;
	m_data_size = size;
}

void EnemyData::Delete()
{
	m_data = nullptr;
	m_data_size = 0;
}

void EnemyData::Open()
{
	FILE *fp;
	_wfopen_s(&fp, SAVE_NAME, L"r");

	if (fp == nullptr)
	{
		memset(m_data, 0x00, m_data_size);
		return;
	}

	fread(m_data, m_data_size, 1, fp);

	fclose(fp);
}

void EnemyData::Save()
{
	FILE* fp;
	_wfopen_s(&fp, SAVE_NAME, L"w");

	if (fp == nullptr)
		return;

	fwrite(m_data, m_data_size, 1, fp);

	fclose(fp);
}

unique_ptr<wchar_t> EnemyData::ExternalDataOpen(wchar_t* file_name, int* size)
{
	FILE *fp;
	
	char buf[100];
	int c;
	int col = 1;
	int row = 0;

	memset(buf, 0, sizeof(buf));
	_wfopen_s(&fp,file_name, L"r");

	while (fgetc(fp) != '\n'); //�w�b�_�ǂݔ�΂�
	//while (fgetc(fp) != '\n' && !feof(fp));

	while (1)
	{
		while (1)
		{
			c = fgetc(fp);

			//�����Ȃ烋�[�v�𔲂���B
			if (c == EOF)
				return nullptr;

			//�J���}�����s�łȂ���΁A�����Ƃ��ĂȂ���
			if (c != ','&& c != '\n')
				strcat_s(buf, (const char*)&c);
			//�J���}�����s�Ȃ烋�[�v������B
			else
				break;
		}

		//�����ɗ����Ƃ������Ƃ́A1�Z�����̕����񂪏o���オ�����Ƃ�������
		switch (col)
		{
		//1��ڂ͓G��ނ�\���Batoi�֐��Ő��l�Ƃ��đ���B
		case 1:e_data[row].enemy_type = atoi(buf); break;
		//2��ڂ͏o�����ԁB�ȍ~�ȗ��B
		case 2:e_data[row].in_time = atoi(buf); break;
		case 3:e_data[row].x = atoi(buf); break;
		case 4:e_data[row].y = atoi(buf); break;
		case 5:e_data[row].enemy_speed = atoi(buf); break;
		case 6:e_data[row].hp = atoi(buf); break;
		case 7:e_data[row].w = atoi(buf); break;
		case 8:e_data[row].h = atoi(buf); break;
		case 9:e_data[row].stop_time = atoi(buf); break;
		case 10:e_data[row].out_time = atoi(buf); break;
		case 11:e_data[row].item = atoi(buf); break;
		case 12:e_data[row].point = atoi(buf); break;
		}
		//�o�b�t�@��������
		memset(buf, 0, sizeof(buf));
		//�񐔂𑫂�
		++col;

		//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
		if (c == '\n')
		{
			col = 1;
			++row;
		}
	}
}