#include "basic.h"

void CBasic::InitBasic()//��ʼ����������
{
	this->C_ItemData.GetItemDataFile(&this->M_ImageData);
	this->C_MonsterData.getVMonsterDataFile(&this->M_ImageData);
	this->C_CMapBasicData.GetMapFile(&this->M_ImageData);
}

