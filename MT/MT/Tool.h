#pragma once
#include "head.h"
#include "common.h"



enum DATATYPE
{
	MONSTERDATA = 0x1 << 0,				//怪物数据
	ITEMDATA = 0x1 << 1,				//道具数据
	MAPDATA = 0x1 << 2,					//地图关卡数据
	MAPMONSTERDATA = 0x1 << 3,			//地图内怪物数据
	MAPITEMDATA = 0x1 << 4,				//地图内道具数据
	FIGUREMDATA = 0x1 << 5,				//人物数据
	MAPDATA2 = 0x1 << 6,				//地图数据

};

enum KEYBOARD
{
	KEY_NONE = 0x1 >> 1,		//无按键
	KEY_LEFT = 0x1 << 0,		//按键左
	KEY_UP = 0x1 << 1,			//按键上
	KEY_RIGHT = 0x1 << 2,		//按键右
	KEY_DOWN = 0x1 << 3,		//按键下
};
class CTool
{
public:

	static void GetFile(TSTRING FileName, void* data2, DATATYPE type);//读取文件
	static void GetFile(TSTRING FileName, void* data2, DATATYPE type, void* data);//读取文件	
	static void MyDraw(D3DXVECTOR3 pos, TSTRING FileName, int ID, DATATYPE type);//绘制
	//static void MyDraw(D3DXVECTOR3 pos, TSTRING FileName, int ID, DATATYPE type,int (*Map)[11]);//地图绘制
	static bool Collision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float length, float width);//检测碰撞
};

