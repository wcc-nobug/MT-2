#pragma once
#include"head.h"
#include "Graphic.h"
class CPerson
{
public:
	int level;
	int blood ;
	int ATK;
	int DEF ;
	int EXP ;
	int Gold;
	int YellowKey ;
	int BlueKey ;
	int	RedKey;
	D3DXVECTOR3 PersonPos;
	D3DXVECTOR3 NewPersonPos{5*37,9*37,0};
	MyImageInfo PersonPhoto[16];
public:
	void initPerson();	//初始化人物	
	void PersonMove(D3DXVECTOR3 pos);	//人物移动
};

