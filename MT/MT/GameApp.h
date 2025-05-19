#pragma once
#include"head.h"
#include "basic.h"
#include "role.h"
enum  ITEM_OR_MONSTER
{
	ITEM = 0x1 << 1,
	MONSTER = 0x1 << 2,
};
class CGameApp
{
public:
	int I_dialog[10] = {0};									//对话顺序
	int keyboard;										//键盘摁下的值
	int Collision_Item_or_Monster;						//碰撞的类型
	bool WhetherKey = false;							//检测键盘是否摁下
	CMapManager C_MapManager;							//所有关卡地图内所有数据
	CBasic C_CBasic;									//存储所有的基本数据
	CPerson C_PersonObj;								//人物
	void initGame();								//初始化
	void MyDraw();									//绘制
	int Collision();			//检测是否发生碰撞 1是地图，2是怪物，4是道具
	bool combat();									//与怪物战斗
	void GamePlay();								//游戏玩法
	int UseItem();									//使用道具
	int dialog();									//对话
};

