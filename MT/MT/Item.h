#pragma once
#include "head.h"
#include "Graphic.h"
class CItemData
{
public:
	int ID;
	TSTRING MonsterName;
	TSTRING MonsterPhoto;
	int function;
	int attributes;
	bool buy;
	int Gold;
};

class CItem
{
public:
	map<int,CItemData> M_CItem;
	void GetItemDataFile(map<int, MyImageInfo> *M_ImageData);
};

class CMapItem
{
public:	
	int ID;
	COORD pos;
	//��ȡ�ļ�һ�е����ݣ�
	virtual void GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem);
	virtual bool OPenTheDoor(int &amount);//��
	virtual void key(int &key);			//Կ��
	virtual void PotionEffect(int &x);	//ҩ��


	//�麯��¥�ݵĽӿ�
	virtual COORD alt(int x,int y);
	virtual COORD gte();
	virtual void Tp_lever(int &lever, D3DXVECTOR3 & NewPosTemp, D3DXVECTOR3 &PosTemp);
};

class CStairsUP :public CMapItem//¥����
{
public:
	COORD TpPos;
	//¥���ϸ�д��x,y������д
	virtual COORD alt(int x, int y);
	virtual COORD gte();
	//¥���϶�ȡ�ļ�һ�к�����д
	virtual void GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem) override;
	//¥���Ϲؿ��Լ����ﴫ����д
	virtual void Tp_lever(int& lever, D3DXVECTOR3& NewPosTemp, D3DXVECTOR3& PosTemp) override;

};
class CStairsDown :public CMapItem//¥����
{
public:
	COORD TpPos;
	//¥���¸�дx,y������д
	virtual COORD gte();
	virtual COORD alt(int x, int y);
	//¥���¶�ȡ�ļ�һ�к�����д
	virtual void GetMapItem( FILE* file, void* ptr, list<CMapItem*>* L_CMapItem) override;
	//¥���¹ؿ��Լ����ﴫ����д
	virtual void Tp_lever(int& lever, D3DXVECTOR3 & NewPosTemp, D3DXVECTOR3 &PosTemp) override;
};
class CYellowDoor :public CMapItem//����
{
public:

};
class CBlueDoor :public CMapItem//����
{
public:
};
class CRedDoor :public CMapItem//����
{
public:
};
class CYellowKey :public CMapItem//��Կ��
{
public:
};
class CBlueKey :public CMapItem//��Կ��
{
public:
};
class CRedKey :public CMapItem//��Կ��
{
public:
};
class CGoldenKey :public CMapItem//��Կ��
{
public:
};
class CYelloPotion :public CMapItem//��ƿ
{
public:
	virtual void PotionEffect(int &x)override;
};
class CPurplePotion :public CMapItem//��ƿ
{
public:
	virtual void PotionEffect(int& x)override;
};
class CGreenPotion :public CMapItem//��ƿ//CGreenPotion
{
public:
	virtual void PotionEffect(int& x)override;
};
class CRedPotion :public CMapItem//��ƿ
{
public:
	virtual void PotionEffect(int& x)override;
};
class CJadePotion :public CMapItem//��ƿ
{
public:
	virtual void PotionEffect(int& x)override;
};
class CRedGem :public CMapItem//�챦ʯ
{
public:
	virtual void PotionEffect(int& x)override;
};
class CGreenGem :public CMapItem//�̱�ʯ
{
public:
	virtual void PotionEffect(int& x)override;
};
class CBlueGem :public CMapItem//����ʯ
{
public:
	virtual void PotionEffect(int& x)override;
};
class CGold :public CMapItem//���
{
public:
	virtual void PotionEffect(int& x)override;
};
class CJadeSword :public CMapItem//��潣
{
public:
	virtual void PotionEffect(int& x)override;
};
class CIronSword :public CMapItem//����
{
public:
	virtual void PotionEffect(int& x)override;
};
class CStarSword :public CMapItem//�ǹ���
{
public:
	virtual void PotionEffect(int& x)override;
};
class CHammer :public CMapItem//����
{
public:
	virtual void PotionEffect(int& x)override;
};
class CLightShield :public CMapItem//��â���
{
public:
};
class CHoe :public CMapItem//��ͷ
{
public:
};
class CHandrail :public CMapItem//����
{
public:
};
class CCrucifix :public CMapItem//ʮ�ּ�
{
public:
};
class CFeather :public CMapItem//��ë
{
public:
};
class CRedMerchant	:public CMapItem//������
{
public:
};
class CGreedMerchant :public CMapItem//������
{
public:
};
class CElf	:public CMapItem//����
{
public:
};