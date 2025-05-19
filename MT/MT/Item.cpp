#include "Item.h"
#include "Tool.h"
//读取全部道具信息
void CItem::GetItemDataFile(map<int, MyImageInfo>* M_ImageData)
{
	CTool::GetFile(L"../bin/data/item.txt", &this->M_CItem, ITEMDATA, M_ImageData);
}

//读取文件一行的内容；
void CMapItem::GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem)
{
	CMapItem* tempA = reinterpret_cast<CMapItem*>(ptr);
	int x, y;
	fscanf(file, "%d%d", &x, &y);
	tempA->pos.X = x;
	tempA->pos.Y = y;
	L_CMapItem->push_back(tempA);
}
//门
bool CMapItem::OPenTheDoor(int& amount)
{
	if (amount > 0)
	{
		amount -= 1;
		return true;
	}
	else
	{
		return false;
	}

}
//钥匙
void CMapItem::key(int& key)
{
	key += 1;
}
//药剂
void CMapItem::PotionEffect(int &x)
{
}
//虚函数楼梯传送的alt接口
COORD CMapItem::alt(int x, int y)
{
	return COORD();
}
//虚函数楼梯传送的get接口
COORD CMapItem::gte()
{
	return COORD();
}
//上下楼梯的接口
void CMapItem::Tp_lever(int& lever, D3DXVECTOR3& NewPosTemp, D3DXVECTOR3& PosTemp)
{

}

//楼梯上改写下x,y函数重写
COORD CStairsUP::alt(int x, int y)
{
	TpPos.X = x;
	TpPos.Y = y;
	return TpPos;
}
//楼梯上改写gti函数重写
COORD CStairsUP::gte()
{
	return TpPos;
}

//楼梯上读取文件一行函数重写
void CStairsUP::GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem)
{
	CMapItem* temp = reinterpret_cast<CMapItem*>(ptr);
	COORD TempPos;
	int x, y, x1, y1;
	fscanf(file, "%d%d%d%d", &x, &y, &x1, &y1);
	temp->pos.X = x;
	temp->pos.Y = y;
	TempPos.X = x1;
	TempPos.Y = y1;
	temp->alt(TempPos.X, TempPos.Y);
	L_CMapItem->push_back(temp);
}
void CStairsUP::Tp_lever(int& lever, D3DXVECTOR3& NewPosTemp, D3DXVECTOR3& PosTemp)
{

	lever -= 1;
	float x, y, z;
	x = this->TpPos.X * 37.0f;
	y = this->TpPos.Y * 37.0f;
	z = 0;
	NewPosTemp = { x,y,z };
	PosTemp = { x,y,z };

}
//楼梯上关卡以及人物传送重写

COORD CStairsDown::gte()
{
	return TpPos;
}
//楼梯下改写下x,y函数重写
COORD CStairsDown::alt(int x, int y)
{
	TpPos.X = x;
	TpPos.Y = y;
	return TpPos;
}

//楼梯下读取文件一行函数重写
void CStairsDown::GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem)
{
	CMapItem* temp = reinterpret_cast<CMapItem*>(ptr);
	int x, y;
	fscanf(file, "%d%d%d%d", &temp->pos.X, &temp->pos.Y, &x, &y);
	temp->alt(x, y);
	L_CMapItem->push_back(temp);
}
//楼梯下关卡切换以及人物传送重写
void CStairsDown::Tp_lever(int& lever, D3DXVECTOR3& NewPosTemp, D3DXVECTOR3& PosTemp)
{
	lever += 1;
	float x, y, z;
	x = this->TpPos.X * 37.0f;
	y = this->TpPos.Y * 37.0f;
	z = 0;
	NewPosTemp = { x,y,z };
	PosTemp = { x,y,z };
}
//黄色药剂效果
void CYelloPotion::PotionEffect(int &x)
{
	x += 100;
}
//黄色药剂效果

void CPurplePotion::PotionEffect(int& x)
{
	x += 10;
}
//绿色药剂效果

void CGreenPotion::PotionEffect(int& x)
{
	x += 500;
}
//红色药剂效果
void CRedPotion::PotionEffect(int& x)
{
	x += 50;
}

void CJadePotion::PotionEffect(int& x)
{
	x += 5000;
}

void CRedGem::PotionEffect(int& x)
{
	x += 100;
}

void CBlueGem::PotionEffect(int& x)
{
	x += 100;
}

void CGreenGem::PotionEffect(int& x)
{
	x += 1000;
}

void CGold::PotionEffect(int& x)
{
	x += 500;
}

void CJadeSword::PotionEffect(int& x)
{
	x += 100;
}

void CIronSword::PotionEffect(int& x)
{
	x += 150;
}

void CStarSword::PotionEffect(int& x)
{
	x += 500;
}

void CHammer::PotionEffect(int& x)
{
	x += 250;
}
