#pragma once
#include "head.h"
#include "common.h"



enum DATATYPE
{
	MONSTERDATA = 0x1 << 0,				//��������
	ITEMDATA = 0x1 << 1,				//��������
	MAPDATA = 0x1 << 2,					//��ͼ�ؿ�����
	MAPMONSTERDATA = 0x1 << 3,			//��ͼ�ڹ�������
	MAPITEMDATA = 0x1 << 4,				//��ͼ�ڵ�������
	FIGUREMDATA = 0x1 << 5,				//��������
	MAPDATA2 = 0x1 << 6,				//��ͼ����

};

enum KEYBOARD
{
	KEY_NONE = 0x1 >> 1,		//�ް���
	KEY_LEFT = 0x1 << 0,		//������
	KEY_UP = 0x1 << 1,			//������
	KEY_RIGHT = 0x1 << 2,		//������
	KEY_DOWN = 0x1 << 3,		//������
};
class CTool
{
public:

	static void GetFile(TSTRING FileName, void* data2, DATATYPE type);//��ȡ�ļ�
	static void GetFile(TSTRING FileName, void* data2, DATATYPE type, void* data);//��ȡ�ļ�	
	static void MyDraw(D3DXVECTOR3 pos, TSTRING FileName, int ID, DATATYPE type);//����
	//static void MyDraw(D3DXVECTOR3 pos, TSTRING FileName, int ID, DATATYPE type,int (*Map)[11]);//��ͼ����
	static bool Collision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float length, float width);//�����ײ
};

