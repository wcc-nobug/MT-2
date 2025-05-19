#include "basic.h"

void CBasic::InitBasic()//初始化基本数据
{
	this->C_ItemData.GetItemDataFile(&this->M_ImageData);
	this->C_MonsterData.getVMonsterDataFile(&this->M_ImageData);
	this->C_CMapBasicData.GetMapFile(&this->M_ImageData);
}

