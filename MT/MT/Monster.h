#pragma once
#include "head.h"
#include "Tool.h"
#include "Graphic.h"
class CMonsterData
{
public:
	int ID;
	TSTRING MonsterName;
	TSTRING MonsterPhoto;
	int blood;
	int ATK;
	int DEF;
	int EXP;
	int Gold;
};


class CMonster
{
private:
public:
	map<int,CMonsterData> M_Monster;			//怪物基本数据
	void getVMonsterDataFile(map<int, MyImageInfo> *M_MapImage);
	
};

class CMapMonster
{
public:
	int ID;
	COORD pos;
};
