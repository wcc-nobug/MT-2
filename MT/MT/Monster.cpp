#include "Monster.h"

void CMonster::getVMonsterDataFile(map<int, MyImageInfo> *M_MapImage)
{
	CTool::GetFile(L"../bin/data/monster_info.txt", &this->M_Monster, MONSTERDATA, M_MapImage);
}


