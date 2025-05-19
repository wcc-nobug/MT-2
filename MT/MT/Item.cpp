#include "Item.h"
#include "Tool.h"
//��ȡȫ��������Ϣ
void CItem::GetItemDataFile(map<int, MyImageInfo>* M_ImageData)
{
	CTool::GetFile(L"../bin/data/item.txt", &this->M_CItem, ITEMDATA, M_ImageData);
}

//��ȡ�ļ�һ�е����ݣ�
void CMapItem::GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem)
{
	CMapItem* tempA = reinterpret_cast<CMapItem*>(ptr);
	int x, y;
	fscanf(file, "%d%d", &x, &y);
	tempA->pos.X = x;
	tempA->pos.Y = y;
	L_CMapItem->push_back(tempA);
}
//��
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
//Կ��
void CMapItem::key(int& key)
{
	key += 1;
}
//ҩ��
void CMapItem::PotionEffect(int &x)
{
}
//�麯��¥�ݴ��͵�alt�ӿ�
COORD CMapItem::alt(int x, int y)
{
	return COORD();
}
//�麯��¥�ݴ��͵�get�ӿ�
COORD CMapItem::gte()
{
	return COORD();
}
//����¥�ݵĽӿ�
void CMapItem::Tp_lever(int& lever, D3DXVECTOR3& NewPosTemp, D3DXVECTOR3& PosTemp)
{

}

//¥���ϸ�д��x,y������д
COORD CStairsUP::alt(int x, int y)
{
	TpPos.X = x;
	TpPos.Y = y;
	return TpPos;
}
//¥���ϸ�дgti������д
COORD CStairsUP::gte()
{
	return TpPos;
}

//¥���϶�ȡ�ļ�һ�к�����д
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
//¥���Ϲؿ��Լ����ﴫ����д

COORD CStairsDown::gte()
{
	return TpPos;
}
//¥���¸�д��x,y������д
COORD CStairsDown::alt(int x, int y)
{
	TpPos.X = x;
	TpPos.Y = y;
	return TpPos;
}

//¥���¶�ȡ�ļ�һ�к�����д
void CStairsDown::GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem)
{
	CMapItem* temp = reinterpret_cast<CMapItem*>(ptr);
	int x, y;
	fscanf(file, "%d%d%d%d", &temp->pos.X, &temp->pos.Y, &x, &y);
	temp->alt(x, y);
	L_CMapItem->push_back(temp);
}
//¥���¹ؿ��л��Լ����ﴫ����д
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
//��ɫҩ��Ч��
void CYelloPotion::PotionEffect(int &x)
{
	x += 100;
}
//��ɫҩ��Ч��

void CPurplePotion::PotionEffect(int& x)
{
	x += 10;
}
//��ɫҩ��Ч��

void CGreenPotion::PotionEffect(int& x)
{
	x += 500;
}
//��ɫҩ��Ч��
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
