#include "GameApp.h"
#include "Item.h"
void CGameApp::initGame()//游戏初始化
{
	this->C_CBasic.InitBasic();				//初始化基本数据
	this->C_MapManager.initMapManager();	//初始化地图内所有信息
	this->C_PersonObj.initPerson();			//初始化人物
}
//绘制
void CGameApp::MyDraw()
{
	//绘制地图
	{
		D3DXVECTOR3 MapPos1(0, 0, 0);
		CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[7], MapPos1, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
		D3DXVECTOR3 MapPos2(11*37+42,42 , 0);
		CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[8], MapPos1, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
		TSTRING str[10];
		str[0] = to_wstring(this->C_PersonObj.blood);
		str[1] = to_wstring(this->C_PersonObj.ATK);
		str[2] = to_wstring(this->C_PersonObj.DEF);
		str[3] = to_wstring(this->C_PersonObj.Gold);
		str[4] = to_wstring(this->C_PersonObj.EXP);
		str[5] = to_wstring(this->C_PersonObj.YellowKey);
		str[6] = to_wstring(this->C_PersonObj.BlueKey);
		str[7] = to_wstring(this->C_PersonObj.RedKey);
		CGraphic::GetSingleObjPtr()->DrawText(str[0], RECT{ 131, 45,	 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
		CGraphic::GetSingleObjPtr()->DrawText(str[0], RECT{ 131, 45,	 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);






		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				float x = j * 37;
				float y = i * 37;
				float z = 0;
				D3DXVECTOR3 MapPos(x, y, z);
				int aa = this->C_MapManager.V_CMap[this->C_MapManager.level].V_MapDataManage[0].MapData[i][j];//读取地图内的数据

				CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[aa], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

			}
		}
	}
	
#
	//绘制怪物
	for (list<CMapMonster>::iterator it = this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMonsterObj.begin(); it != this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMonsterObj.end(); it++)
	{
		COORD tempPos = it->pos;
		int tempID = it->ID;
		float x = tempPos.X * 37;
		float y = tempPos.Y * 37;
		float z = 0;
		D3DXVECTOR3 MapPos(x, y, z);
		CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[tempID], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	}
	//绘制道具
	for (list<CMapItem*>::iterator it = this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.begin(); it != this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.end();it++)
	{
		
		COORD tempPos = (*it)->pos;
		int tempID = (*it)->ID;
		float x = tempPos.X * 37;
		float y = tempPos.Y * 37;
		float z = 0;
		D3DXVECTOR3 MapPos(x, y, z);
		CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[tempID], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	}
	//绘制人
	{

		static int x = 0;
		static int x1 = 0;
		D3DXVECTOR3 MapPos = this->C_PersonObj.PersonPos;
		if (this->WhetherKey)
		{
			x1++;
			if (x1 == 4)
			{
				x1 = 0;
				this->WhetherKey = false;
			}

			switch (this->keyboard)
			{
			case KEY_LEFT:
				x = 4;
				x += x1;
				CGraphic::GetSingleObjPtr()->DrawTex(this->C_PersonObj.PersonPhoto[x], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
				break;
			case KEY_UP:
				x = 12;
				x += x1;
				CGraphic::GetSingleObjPtr()->DrawTex(this->C_PersonObj.PersonPhoto[x], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
				break;
			case KEY_RIGHT:
				x = 8;
				x += x1;
				CGraphic::GetSingleObjPtr()->DrawTex(this->C_PersonObj.PersonPhoto[x], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
				break;
			case KEY_DOWN:
				x = 0;
				x += x1;
				CGraphic::GetSingleObjPtr()->DrawTex(this->C_PersonObj.PersonPhoto[x], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
				break;
			}

		}
		else
		{
			CGraphic::GetSingleObjPtr()->DrawTex(this->C_PersonObj.PersonPhoto[x], MapPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
		}

	}




}
//检测是否发生碰撞
int CGameApp::Collision()
{			
	//检测地图是否发生碰撞
	if (this->C_MapManager.V_CMap[this->C_MapManager.level].CollisionMap(this->C_PersonObj.NewPersonPos))
	{
		this->C_PersonObj.NewPersonPos = this->C_PersonObj.PersonPos;
		return 1;
	}
	//检测怪物碰撞
	else if (this->C_MapManager.V_CMap[this->C_MapManager.level].CollisionMonster(this->C_PersonObj.NewPersonPos))
	{
		//this->C_PersonObj.NewPersonPos = this->C_PersonObj.PersonPos;
		return 4;
	}
	//检测道具碰撞
	else if (this->C_MapManager.V_CMap[this->C_MapManager.level].CollisionItem(this->C_PersonObj.NewPersonPos))
	{
		//this->C_PersonObj.NewPersonPos = this->C_PersonObj.PersonPos;
		return 2;
	}
	else
	{
		this->C_PersonObj.PersonPos = this->C_PersonObj.NewPersonPos;
	}
}

//与怪物战斗
bool CGameApp::combat()
{
	for (auto it = this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMonsterObj.begin();it!= this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMonsterObj.end();it++)
	{
		float x, y, z;
		x = it->pos.X * 37;
		y = it->pos.Y * 37;
		z = 0;
		if (CTool::Collision(this->C_PersonObj.NewPersonPos,{x,y,z}, 37, 37))
		{
			static CMonsterData Attacking_Unit;
			CMonsterData* MonsterData = new CMonsterData;
			*MonsterData = this->C_CBasic.C_MonsterData.M_Monster[it->ID];
			CPerson* PersonData = new CPerson;
			*PersonData = this->C_PersonObj;
			static int Battle;
			while (true)
			{
				
				
				MonsterData->blood -= PersonData->ATK - MonsterData->DEF;
				PersonData->blood -= MonsterData->ATK - PersonData->DEF;
				if (MonsterData->blood<=0)		//检测如果可以打过怪物
				{					
					if (Battle < 0)
					{
						Battle = 0;
					}
					if (Battle == 0)
					{

						Attacking_Unit = this->C_CBasic.C_MonsterData.M_Monster[it->ID];
						Battle = 1;

					}
					
					*MonsterData = this->C_CBasic.C_MonsterData.M_Monster[it->ID];
					D3DXVECTOR3 MapPos1(0, 0, 0);
					TSTRING str[6];
					
					str[0] = to_wstring(Attacking_Unit.blood);
					str[1] = to_wstring(Attacking_Unit.ATK);
					str[2] = to_wstring(Attacking_Unit.DEF);
					str[3] = to_wstring(this->C_PersonObj.blood);
					str[4] = to_wstring(this->C_PersonObj.ATK);
					str[5] = to_wstring(this->C_PersonObj.DEF);		
					CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[9], MapPos1, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
					CGraphic::GetSingleObjPtr()->DrawText(str[0], RECT{ 131, 45,	 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
					CGraphic::GetSingleObjPtr()->DrawText(str[1], RECT{ 131, 81,		1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
					CGraphic::GetSingleObjPtr()->DrawText(str[2], RECT{ 131, 115, 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
					CGraphic::GetSingleObjPtr()->DrawText(str[3], RECT{ 220, 45, 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
					CGraphic::GetSingleObjPtr()->DrawText(str[4], RECT{ 235, 81,	 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
					CGraphic::GetSingleObjPtr()->DrawText(str[5], RECT{ 235, 115, 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
					
					if (Battle == 1)		
					{
						
						this->C_PersonObj.blood -= Attacking_Unit.ATK - this->C_PersonObj.DEF;
						
						Battle = 2;			
						Sleep(200);

					}
					else if (Battle == 2)
					{
						Attacking_Unit.blood -= this->C_PersonObj.ATK - Attacking_Unit.DEF;						
						Battle = 1;		
						Sleep(200);
					}					
					if (Attacking_Unit.blood <= 0)
					{
						delete MonsterData;
						delete PersonData;
						this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMonsterObj.erase(it);
						this->C_PersonObj.NewPersonPos = this->C_PersonObj.PersonPos;
						Battle = 0;
						return true;
					}
					
					break;
					
				}
				else if(PersonData->blood <= 0)
				{
					delete MonsterData;
					delete PersonData;
					return false;
				}
				

			}
			
			
			
		}
	}
	
}

//检测碰到的物体，并执行对应的命令
void CGameApp::GamePlay()
{
	if (this->Collision_Item_or_Monster== ITEM)
	{
		if(this->UseItem()==0)
		{
			this->C_PersonObj.NewPersonPos = this->C_PersonObj.PersonPos;
		}

	}
	else if(this->Collision_Item_or_Monster == MONSTER)
	{
		this->combat();
		

	}
	
		
		
}

//使用道具
int CGameApp::UseItem()
{
	//CMapItem* p;
	for (list<CMapItem*>::iterator it = this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.begin(); it != this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.end(); it++)
	{
		float x, y, z;
		x = (*it)->pos.X * 37;
		y = (*it)->pos.Y * 37;
		z = 0;
		if (CTool::Collision(this->C_PersonObj.NewPersonPos, { x,y,z }, 37, 37))
		{
			
			switch ((*it)->ID)
			{
			case 1001:
				if ((*it)->OPenTheDoor(this->C_PersonObj.YellowKey))
				{
					this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);					
				}
				return 1;
			case 1002:
				if ((*it)->OPenTheDoor(this->C_PersonObj.BlueKey))
				{
					this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);					
				}
				return 1;
			case 1003:
				if ((*it)->OPenTheDoor(this->C_PersonObj.RedKey))
				{
					this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);				
				}	
				return 1;
			case 1004:
				(*it)->key(this->C_PersonObj.YellowKey);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;			
			case 1005:
				(*it)->key(this->C_PersonObj.BlueKey);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
				
			case 1006:
				(*it)->key(this->C_PersonObj.RedKey);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
				
			case 1007:
				(*it)->key(this->C_PersonObj.YellowKey);
				(*it)->key(this->C_PersonObj.BlueKey);
				(*it)->key(this->C_PersonObj.RedKey);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
				
			case 1008:							
				(*it)->Tp_lever(this->C_MapManager.level, this->C_PersonObj.NewPersonPos, this->C_PersonObj.PersonPos);
				return 1;			
			case 1009:				
				(*it)->Tp_lever(this->C_MapManager.level, this->C_PersonObj.NewPersonPos, this->C_PersonObj.PersonPos);
				return 1;				
			case 1010:
				(*it)->PotionEffect(this->C_PersonObj.DEF);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1011:
				(*it)->PotionEffect(this->C_PersonObj.EXP);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1012:
				(*it)->PotionEffect(this->C_PersonObj.blood);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1013:
				(*it)->PotionEffect(this->C_PersonObj.ATK);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1014:
				(*it)->PotionEffect(this->C_PersonObj.blood);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1015:
				(*it)->PotionEffect(this->C_PersonObj.ATK);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1016:
				(*it)->PotionEffect(this->C_PersonObj.Gold);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1017:
				(*it)->PotionEffect(this->C_PersonObj.DEF);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1018:
				(*it)->PotionEffect(this->C_PersonObj.Gold);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1019:
				(*it)->PotionEffect(this->C_PersonObj.ATK);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1020:
				(*it)->PotionEffect(this->C_PersonObj.ATK);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1021:
				(*it)->PotionEffect(this->C_PersonObj.ATK);
				this->C_MapManager.V_CMap[this->C_MapManager.level].L_CMapItem.erase(it);
				return 1;
			case 1022:

				return 1;
			case 1023:
				return 1;
			case 1024:
				return 1;
			case 1025:
				return 1;
			case 1026:
				return 1;
			case 1027:
				return 1;
			case 1028:
				return 1;
			case 1029:
				return 1;
			case 1030:
				if (this->dialog()==1)
				{
					return 1;
				}
				
			
			}
		}		
	}
	
}

int CGameApp::dialog()
{
	
	D3DXVECTOR3 MapPos1(0, 0, 0);	
	switch (I_dialog[0])
	{
	case 0:		
		CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[10], MapPos1, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
		CGraphic::GetSingleObjPtr()->DrawText(_T("这里是哪里？"), RECT{ 263, 300, 1000, 1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
		break;
	case 1:
		CGraphic::GetSingleObjPtr()->DrawTex(this->C_CBasic.M_ImageData[11], MapPos1, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
		CGraphic::GetSingleObjPtr()->DrawText(_T("那你别管，往前走去救公主吧"), RECT{ 75, 198, 1000,1000 }, DT_LEFT | DT_TOP | DT_SINGLELINE, 0xFFFFFFFF);
		
		return 1;
	}
}
