#pragma once
#include "head.h"
#include "Item.h"
#include "Monster.h"
#include "Map.h"
#include "Singleton.h"
#include "Graphic.h"


class CBasic//�洢���еĻ�������
{
public:
	//map<int, TSTRING> M_ImageName;
	map<int, MyImageInfo> M_ImageData;//ͼƬ
	CItem C_ItemData;					//����
	CMonster C_MonsterData;				//����
	CMapBasicData  C_CMapBasicData;		//��ͼ
	void InitBasic();//��ʼ����������
	

};

