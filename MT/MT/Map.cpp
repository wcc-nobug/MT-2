#include "Map.h"
#include "Tool.h"



void CMap::GetMapItem(int level)
{
	TSTRING StrFileName = {};
	TSTRING buf = { L"../bin/data/map/mapData" };
	TSTRING buf1 = to_wstring(level);
	TSTRING buf2 = { L"Item.txt" };
	StrFileName = buf + buf1 + buf2;
	CTool::GetFile(StrFileName, &L_CMapItem, MAPITEMDATA);
}

void CMap::GetMap(int level)
{
	TSTRING StrFileName = {};
	TSTRING buf = { L"../bin/data/map/mapData" };
	TSTRING buf1 = to_wstring(level);
	TSTRING buf2 = { L".txt" };
	StrFileName = buf + buf1 + buf2;
	CTool::GetFile(StrFileName, &V_MapDataManage, MAPDATA);
}

void CMap::GetMapMonster(int level)
{
	TSTRING StrFileName = {};
	TSTRING buf = { L"../bin/data/map/mapData" };
	TSTRING buf1 = to_wstring(level);
	TSTRING buf2 = { L"Monster.txt" };
	StrFileName = buf + buf1 + buf2;
	CTool::GetFile(StrFileName, &L_CMonsterObj, MAPMONSTERDATA);
}
//检测是否碰到地图
bool CMap::CollisionMap(D3DXVECTOR3 NewPersonPos)				
{
	float x1, y1, z1;

	//检测地图碰撞
	for (int i = 0; i < 11; i++)
	{

		for (int j = 0; j < 11; j++)
		{
			x1 = j * 37;
			y1 = i * 37;
			z1 = 0;

			D3DXVECTOR3 tempPos{ x1,y1,z1 };
			if (this->V_MapDataManage[0].MapData[i][j]!=0)
			{
				if (CTool::Collision(NewPersonPos, tempPos, 37.0f, 37.0f))
				{
					return true;
				}
			}
			


		}
	}
	return false;
}
//检测是否碰到怪物
bool CMap::CollisionMonster(D3DXVECTOR3 NewPersonPos)
{
	float x, y, z;
	for (auto it = this->L_CMonsterObj.begin(); it != this->L_CMonsterObj.end(); it++)
	{
		x = it->pos.X * 37 ;
		y = it->pos.Y * 37 ;
		z = 0;
		D3DXVECTOR3 tempPos{ x,y,z };
		if (CTool::Collision(NewPersonPos,tempPos,37,37))
		{
			return true;
		}
	}
	return false;
}
//检测是否碰到道具
 bool CMap::CollisionItem(D3DXVECTOR3 NewPersonPos)
 {
 	float x, y, z;
 	for (auto it = this->L_CMapItem.begin(); it != this->L_CMapItem.end(); it++)
 	{
 		x = (*it)->pos.X * 37;
 		y = (*it)->pos.Y * 37;
 		z = 0;
 		D3DXVECTOR3 tempPOS{ x,y,z };
 		if (CTool::Collision(NewPersonPos, tempPOS,37,37))
 		{
 			return true;
 		}
 	}
 	return false;
 }
 

//初始化地图信息
void CMapManager::initMapManager()
{


	for (int i = 0; i <= 21; i++)
	{
		CMap* temp = new CMap;
		temp->GetMap(i);
		temp->GetMapItem(i);
		temp->GetMapMonster(i);
		V_CMap.push_back(*temp);
		delete temp;
	}

}



void CMapBasicData::GetMapFile(map<int, MyImageInfo>* M_ImageData)
{
	CTool::GetFile(L"../bin/data/map.txt", M_ImageData, MAPDATA2);
}
