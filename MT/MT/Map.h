#pragma once
#include"head.h"
#include "Monster.h"
#include "Item.h"

class CMapData
{
public:
	int MapData[11][11];
};

class CMap			//每一个要有当前地图的所有数据
{
public:	
	vector<CMapData> V_MapDataManage;	//存储了当前的地图数据
	list<CMapMonster> L_CMonsterObj;	//当前地图的怪物数据
	list<CMapItem*> L_CMapItem;			//存储了当前地图道具数据
								
	void GetMapItem(int level);			//读取当前关卡道具
	void GetMap(int level);				//读取当前关卡地图
	void GetMapMonster(int level);		//读取当前关卡怪物

	bool CollisionMap(D3DXVECTOR3 NewPersonPos);				//检测是否碰到地图
	bool CollisionMonster(D3DXVECTOR3 NewPersonPos);			//检测是否碰到怪物
	bool CollisionItem(D3DXVECTOR3 NewPersonPos);				//检测是否碰到道具

// 	void DrawMap();						//绘制地图
// 	void DrawMapItem();					//绘制道具
// 	void DrawMapMonster();				//绘制怪物
};
class CMapManager
{
public:
	int level;
	vector<CMap> V_CMap;//21个，每个对应一个关
	//	CImage C_ImageObj;
		//初始化地图
	void initMapManager();//初始化21关地图内数据
};

class CMapBasicData
{
public:
	int a;
	void GetMapFile(map<int, MyImageInfo>  *M_ImageData);

};
