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
	//读取文件一行的内容；
	virtual void GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem);
	virtual bool OPenTheDoor(int &amount);//门
	virtual void key(int &key);			//钥匙
	virtual void PotionEffect(int &x);	//药剂


	//虚函数楼梯的接口
	virtual COORD alt(int x,int y);
	virtual COORD gte();
	virtual void Tp_lever(int &lever, D3DXVECTOR3 & NewPosTemp, D3DXVECTOR3 &PosTemp);
};

class CStairsUP :public CMapItem//楼梯上
{
public:
	COORD TpPos;
	//楼梯上改写下x,y函数重写
	virtual COORD alt(int x, int y);
	virtual COORD gte();
	//楼梯上读取文件一行函数重写
	virtual void GetMapItem(FILE* file, void* ptr, list<CMapItem*>* L_CMapItem) override;
	//楼梯上关卡以及人物传送重写
	virtual void Tp_lever(int& lever, D3DXVECTOR3& NewPosTemp, D3DXVECTOR3& PosTemp) override;

};
class CStairsDown :public CMapItem//楼梯下
{
public:
	COORD TpPos;
	//楼梯下改写x,y函数重写
	virtual COORD gte();
	virtual COORD alt(int x, int y);
	//楼梯下读取文件一行函数重写
	virtual void GetMapItem( FILE* file, void* ptr, list<CMapItem*>* L_CMapItem) override;
	//楼梯下关卡以及人物传送重写
	virtual void Tp_lever(int& lever, D3DXVECTOR3 & NewPosTemp, D3DXVECTOR3 &PosTemp) override;
};
class CYellowDoor :public CMapItem//黄门
{
public:

};
class CBlueDoor :public CMapItem//蓝门
{
public:
};
class CRedDoor :public CMapItem//红门
{
public:
};
class CYellowKey :public CMapItem//黄钥匙
{
public:
};
class CBlueKey :public CMapItem//蓝钥匙
{
public:
};
class CRedKey :public CMapItem//红钥匙
{
public:
};
class CGoldenKey :public CMapItem//金钥匙
{
public:
};
class CYelloPotion :public CMapItem//黄瓶
{
public:
	virtual void PotionEffect(int &x)override;
};
class CPurplePotion :public CMapItem//紫瓶
{
public:
	virtual void PotionEffect(int& x)override;
};
class CGreenPotion :public CMapItem//绿瓶//CGreenPotion
{
public:
	virtual void PotionEffect(int& x)override;
};
class CRedPotion :public CMapItem//红瓶
{
public:
	virtual void PotionEffect(int& x)override;
};
class CJadePotion :public CMapItem//玉瓶
{
public:
	virtual void PotionEffect(int& x)override;
};
class CRedGem :public CMapItem//红宝石
{
public:
	virtual void PotionEffect(int& x)override;
};
class CGreenGem :public CMapItem//绿宝石
{
public:
	virtual void PotionEffect(int& x)override;
};
class CBlueGem :public CMapItem//蓝宝石
{
public:
	virtual void PotionEffect(int& x)override;
};
class CGold :public CMapItem//金币
{
public:
	virtual void PotionEffect(int& x)override;
};
class CJadeSword :public CMapItem//青锋剑
{
public:
	virtual void PotionEffect(int& x)override;
};
class CIronSword :public CMapItem//铁剑
{
public:
	virtual void PotionEffect(int& x)override;
};
class CStarSword :public CMapItem//星光神剑
{
public:
	virtual void PotionEffect(int& x)override;
};
class CHammer :public CMapItem//铁锤
{
public:
	virtual void PotionEffect(int& x)override;
};
class CLightShield :public CMapItem//光芒神盾
{
public:
};
class CHoe :public CMapItem//锄头
{
public:
};
class CHandrail :public CMapItem//栏杆
{
public:
};
class CCrucifix :public CMapItem//十字架
{
public:
};
class CFeather :public CMapItem//羽毛
{
public:
};
class CRedMerchant	:public CMapItem//红商人
{
public:
};
class CGreedMerchant :public CMapItem//蓝商人
{
public:
};
class CElf	:public CMapItem//精灵
{
public:
};