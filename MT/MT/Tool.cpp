#include "Tool.h"
#include "Monster.h"
#include "Item.h"
#include "Map.h"
#include "Singleton.h"
#include "Graphic.h"
#include "role.h"
void CTool::GetFile(TSTRING FileName, void* data2, DATATYPE type)
{
	FILE* file = _tfopen(FileName.c_str(), TEXT("r"));

	if (type == MONSTERDATA)
	{
		//读取文件要使用ANSI格式代码
		CMonsterData* temp = new CMonsterData;
		vector<CMonsterData>* V_Monster = reinterpret_cast<vector<CMonsterData>*>(data2);
		char buf1[100];
		char buf2[100];

		fgets(buf1, 100, file);
		while ((fscanf(file, " %d%s%s%d%d%d%d%d", &temp->ID, buf1, buf2, &temp->blood, &temp->ATK, &temp->DEF, &temp->EXP, &temp->Gold)) > 0)//读取文件信息
		{



#ifdef _UNICODE
			temp->MonsterName = multi_byte_to_wide_char(buf1, 0);
			temp->MonsterPhoto = multi_byte_to_wide_char(buf2, 0);

#else
			temp->MonsterName = buf1;
			temp->MonsterPhoto = buf2;
#endif

			V_Monster->push_back(*temp);

		}
		delete temp;
	}
	if (type == ITEMDATA)
	{
		//读取文件要使用ANSI格式代码
		CItemData* temp = new CItemData;

		vector<CItemData>* V_CItem = reinterpret_cast<vector<CItemData>*>(data2);
		char buf1[100];
		char buf2[100];

		fgets(buf1, 100, file);
		while ((fscanf(file, " %d%s%s%d%d%d%d", &temp->ID, buf1, buf2, &temp->function, &temp->attributes, &temp->buy, &temp->Gold)) > 0)//读取文件信息
		{


#ifdef _UNICODE
			temp->MonsterName = multi_byte_to_wide_char(buf1, 0);
			temp->MonsterPhoto = multi_byte_to_wide_char(buf2, 0);

#else
			temp->MonsterName = buf1;
			temp->MonsterPhoto = buf2;
#endif

			V_CItem->push_back(*temp);

		}
		delete temp;
	}
	if (type == MAPDATA)
	{
		//map<int, TSTRING>* temp_map = new map<int, TSTRING>;//定义map指针
		CMapData* temp = new CMapData;
		vector<CMapData>* V_MapDataManage = reinterpret_cast <vector< CMapData >*> (data2);
		int x[11][11] = {};

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				fscanf(file, "%d,", &x[i][j]);

			}
		}
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				temp->MapData[i][j] = x[i][j];
			}
		}
		V_MapDataManage->push_back(*temp);


	}
	if (type == MAPMONSTERDATA)
	{
		char buf1[100];
		fgets(buf1, 100, file);
		int x, y;
		CMapMonster* temp = new CMapMonster;
		list<CMapMonster>* L_CMonsterObj = reinterpret_cast<list<CMapMonster>*>(data2);
		while ((fscanf(file, " %d%d%d", &temp->ID, &x, &y) > 0))
		{
			temp->pos.X = x;
			temp->pos.Y = y;
			L_CMonsterObj->push_back(*temp);
		}
		delete temp;


	}
	if (type == MAPITEMDATA)
	{
		char buf1[100];
		fgets(buf1, 100, file);
		int x = 0;
		list<CMapItem*>* L_CMapItem = reinterpret_cast<list<CMapItem*>*>(data2);

		while ((fscanf(file, " %d", &x) > 0))
		{
			CMapItem* temp = NULL; 
			switch (x)
			{
			case 1001://黄门
				temp = new CYellowDoor;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);

				break;
			case 1002://蓝门
				temp = new CBlueDoor;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);

				break;
			case 1003://红门
				temp = new CRedDoor;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1004://黄钥匙
				temp = new CYellowKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1005://蓝钥匙
				temp = new CBlueKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1006://红钥匙
				temp = new CRedKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1007://金钥匙
				temp = new CGoldenKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1008://楼梯上
				temp = new CStairsUP;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1009://楼梯下
				temp = new CStairsDown;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1010://黄瓶
				temp = new CYelloPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1011://紫瓶
				temp = new CPurplePotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1012://绿瓶
				temp = new CGreenPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1013://红瓶
				temp = new CRedPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1014://玉瓶
				temp = new CJadePotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1015://红宝石
				temp = new CRedGem;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1016://绿宝石
				temp = new CGreenGem;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1017://蓝宝石
				temp = new CBlueGem;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1018://金币
				temp = new CGold;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1019://青锋剑
				temp = new CJadeSword;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1020://铁剑
				temp = new CIronSword;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1021://星光神剑
				temp = new CStarSword;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1022://铁锤
				temp = new CHammer;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1023://光芒神盾
				temp = new CLightShield;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1024://锄头
				temp = new CHoe;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1025://栏杆
				temp = new CHandrail;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1026://十字架
				temp = new CCrucifix;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1027://羽毛
				temp = new CFeather;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1028://红商人
				temp = new CRedMerchant;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1029://蓝商人
				temp = new CGreedMerchant;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1030://精灵
				temp = new CElf;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			}
			
		}

	}
	if (type == MAPDATA2)
	{
		map<int, MyImageInfo>* M_MapImage = reinterpret_cast <map<int, MyImageInfo>*> (data2);
		char buf1[100];
		int x;
		TSTRING buf2;
		TSTRING buf3 = L"../bin/mapImage/";
		fgets(buf1, 100, file);
		MyImageInfo temp;
		while ((fscanf(file, " %d%s", &x, buf1)) > 0)//读取文件信息
		{



#ifdef _UNICODE
			buf2 = multi_byte_to_wide_char(buf1, 0);

#else
			temp->MonsterName = buf1;
#endif
			buf2 = buf3 + buf2;
			//const TCHAR* buf4 = &buf2;
			CGraphic::GetSingleObjPtr()->LoadTex(buf2.c_str(), temp, 0xff00000);
			M_MapImage->insert(pair<int, MyImageInfo>(x, temp));

		}
	}
	if (type == FIGUREMDATA)
	{
		char buf[100] = {};
		fgets(buf, 100, file);
		float* FTemp = new float;
		float* Ftemp2 = new float;
		CPerson* P_Person = reinterpret_cast<CPerson*>(data2);
		while ((fscanf(file, "%d%d%d%d%d%d%d%d%d%f%f", &P_Person->level, &P_Person->blood, &P_Person->ATK, &P_Person->DEF, &P_Person->EXP, &P_Person->Gold, &P_Person->YellowKey, &P_Person->BlueKey, &P_Person->RedKey, FTemp, Ftemp2) > 0))
		{
			P_Person->PersonPos = { *FTemp,*Ftemp2,0.0f };
		}
		delete FTemp;
		delete Ftemp2;
	}
}


void CTool::GetFile(TSTRING FileName, void* data2, DATATYPE type, void* data)
{
	FILE* file = _tfopen(FileName.c_str(), TEXT("r"));

	if (type == MONSTERDATA)
	{
		//读取文件要使用ANSI格式代码
		CMonsterData* temp = new CMonsterData;
		map<int, MyImageInfo>* M_MapImage = reinterpret_cast <map<int, MyImageInfo>*> (data);
		map<int, CMonsterData> *M_Monster = reinterpret_cast<map<int, CMonsterData>*>(data2);
		char buf1[100];
		char buf2[100];

		MyImageInfo tempImage;
		fgets(buf1, 100, file);
		while ((fscanf(file, " %d%s%s%d%d%d%d%d", &temp->ID, buf1, buf2, &temp->blood, &temp->ATK, &temp->DEF, &temp->EXP, &temp->Gold)) > 0)//读取文件信息
		{

			TSTRING Sbuf = L"../bin/monsterImage/";
			TSTRING Sbuf3;

#ifdef _UNICODE
			temp->MonsterName = multi_byte_to_wide_char(buf1, 0);
			temp->MonsterPhoto = multi_byte_to_wide_char(buf2, 0);

#else
			temp->MonsterName = buf1;
			temp->MonsterPhoto = buf2;
#endif
			Sbuf3 = temp->MonsterPhoto = multi_byte_to_wide_char(buf2, 0);
			Sbuf = Sbuf + Sbuf3;
			CGraphic::GetSingleObjPtr()->LoadTex(Sbuf.c_str(), tempImage, 0xFFFFFFFF);
			M_MapImage->insert(pair<int, MyImageInfo>(temp->ID, tempImage));
			M_Monster->insert(pair<int, CMonsterData>(temp->ID, *temp));

		}
		delete temp;

	}
	if (type == ITEMDATA)
	{
		//读取文件要使用ANSI格式代码
		CItemData* temp = new CItemData;
		map<int, MyImageInfo>* M_MapImage = reinterpret_cast <map<int, MyImageInfo>*>(data);
		map<int,CItemData>* V_CItem = reinterpret_cast<map<int,CItemData>*>(data2);
		char buf1[100];
		char buf2[100];
		int x;

		MyImageInfo tempImage;
		fgets(buf1, 100, file);
		while ((fscanf(file, " %d%s%s%d%d%d%d", &temp->ID, buf1, buf2, &temp->function, &temp->attributes, &temp->buy, &temp->Gold)) > 0)//读取文件信息
		{
			x = temp->ID;
			TSTRING Sbuf = L"../bin/itemImage/";
			TSTRING Sbuf3;
#ifdef _UNICODE
			temp->MonsterName = multi_byte_to_wide_char(buf1, 0);
			temp->MonsterPhoto = multi_byte_to_wide_char(buf2, 0);

#else
			temp->MonsterName = buf1;
			temp->MonsterPhoto = buf2;
#endif

			Sbuf3 = temp->MonsterPhoto;
			Sbuf = Sbuf + Sbuf3;
			CGraphic::GetSingleObjPtr()->LoadTex(Sbuf.c_str(), tempImage, 0xFFFFFFFF);
			M_MapImage->insert(pair<int, MyImageInfo>(x, tempImage));
			V_CItem->insert(pair<int,CItemData>(x,*temp));

		}
		delete temp;

	}
	if (type == MAPDATA)
	{
		//map<int, TSTRING>* temp_map = new map<int, TSTRING>;//定义map指针
		CMapData* temp = new CMapData;
		map<int, TSTRING>* M_MapImage = reinterpret_cast <map<int, TSTRING>*> (data);
		vector<CMapData>* V_MapDataManage = reinterpret_cast <vector< CMapData >*> (data2);
		int x[11][11] = {};
		TSTRING buf = L"../bin/mapImage/map";
		TSTRING buf2 = L".jpg";
		TSTRING buf3;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				fscanf(file, "%d,", &x[i][j]);
				buf3 = to_wstring(x[i][j]);
				buf = buf + buf3 + buf2;
				M_MapImage->insert(pair<int, TSTRING>(x[i][j], buf));
			}
		}
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				temp->MapData[i][j] = x[i][j];
			}
		}
		V_MapDataManage->push_back(*temp);


	}
	if (type == MAPMONSTERDATA)
	{
		char buf1[100];
		fgets(buf1, 100, file);
		int x, y;
		CMapMonster* temp = new CMapMonster;
		vector<CMapMonster>* V_CMonsterObj = reinterpret_cast<vector<CMapMonster>*>(data2);
		while ((fscanf(file, " %d%d%d", &temp->ID, &x, &y) > 0))
		{
			temp->pos.X = x;
			temp->pos.Y = y;
			V_CMonsterObj->push_back(*temp);
		}
		delete temp;


	}
	if (type == MAPITEMDATA)
	{
		char buf1[100];
		fgets(buf1, 100, file);
		int x = 0;
		list<CMapItem*>* L_CMapItem = reinterpret_cast<list<CMapItem*>*>(data2);

		while ((fscanf(file, " %d", &x) > 0))
		{
			CMapItem* temp = NULL;
			switch (x)
			{
			case 1001://黄门
				temp = new CYellowDoor;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);

				break;
			case 1002://蓝门
				temp = new CBlueDoor;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);

				break;
			case 1003://红门
				temp = new CRedDoor;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1004://黄钥匙
				temp = new CYellowKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1005://蓝钥匙
				temp = new CBlueKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1006://红钥匙
				temp = new CRedKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1007://金钥匙
				temp = new CGoldenKey;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1008://楼梯上
				temp = new CYelloPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1009://楼梯下
				temp = new CStairsDown;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);

				break;
			case 1010://黄瓶
				temp = new CYelloPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1011://紫瓶
				temp = new CPurplePotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1012://绿瓶
				temp = new CGreenPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1013://红瓶
				temp = new CRedPotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1014://玉瓶
				temp = new CJadePotion;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1015://红宝石
				temp = new CRedGem;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1016://绿宝石
				temp = new CGreenGem;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1017://蓝宝石
				temp = new CBlueGem;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1018://金币
				temp = new CGold;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1019://青锋剑
				temp = new CJadeSword;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1020://铁剑
				temp = new CIronSword;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1021://星光神剑
				temp = new CStarSword;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1022://铁锤
				temp = new CHammer;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1023://光芒神盾
				temp = new CLightShield;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1024://锄头
				temp = new CHoe;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1025://栏杆
				temp = new CHandrail;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1026://十字架
				temp = new CCrucifix;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1027://羽毛
				temp = new CFeather;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1028://红商人
				temp = new CRedMerchant;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1029://蓝商人
				temp = new CGreedMerchant;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			case 1030://精灵
				temp = new CElf;
				temp->ID = x;
				temp->GetMapItem(file, temp, L_CMapItem);
				break;
			}
			delete temp;
		}

	}}



bool CTool::Collision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float height, float width)
{
		
	return(pos1.x < pos2.x + width &&
		pos1.x + width > pos2.x &&
		pos1.y < pos2.y + height &&
		pos1.y + height > pos2.y);
}





