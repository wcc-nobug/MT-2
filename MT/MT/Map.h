#pragma once
#include"head.h"
#include "Monster.h"
#include "Item.h"

class CMapData
{
public:
	int MapData[11][11];
};

class CMap			//ÿһ��Ҫ�е�ǰ��ͼ����������
{
public:	
	vector<CMapData> V_MapDataManage;	//�洢�˵�ǰ�ĵ�ͼ����
	list<CMapMonster> L_CMonsterObj;	//��ǰ��ͼ�Ĺ�������
	list<CMapItem*> L_CMapItem;			//�洢�˵�ǰ��ͼ��������
								
	void GetMapItem(int level);			//��ȡ��ǰ�ؿ�����
	void GetMap(int level);				//��ȡ��ǰ�ؿ���ͼ
	void GetMapMonster(int level);		//��ȡ��ǰ�ؿ�����

	bool CollisionMap(D3DXVECTOR3 NewPersonPos);				//����Ƿ�������ͼ
	bool CollisionMonster(D3DXVECTOR3 NewPersonPos);			//����Ƿ���������
	bool CollisionItem(D3DXVECTOR3 NewPersonPos);				//����Ƿ���������

// 	void DrawMap();						//���Ƶ�ͼ
// 	void DrawMapItem();					//���Ƶ���
// 	void DrawMapMonster();				//���ƹ���
};
class CMapManager
{
public:
	int level;
	vector<CMap> V_CMap;//21����ÿ����Ӧһ����
	//	CImage C_ImageObj;
		//��ʼ����ͼ
	void initMapManager();//��ʼ��21�ص�ͼ������
};

class CMapBasicData
{
public:
	int a;
	void GetMapFile(map<int, MyImageInfo>  *M_ImageData);

};
