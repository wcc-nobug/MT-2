#pragma once
#include "head.h"
#include "Item.h"
#include "Monster.h"
#include "Map.h"
#include "Singleton.h"
#include "Graphic.h"


class CBasic//存储所有的基本数据
{
public:
	//map<int, TSTRING> M_ImageName;
	map<int, MyImageInfo> M_ImageData;//图片
	CItem C_ItemData;					//道具
	CMonster C_MonsterData;				//怪物
	CMapBasicData  C_CMapBasicData;		//地图
	void InitBasic();//初始化基本数据
	

};

