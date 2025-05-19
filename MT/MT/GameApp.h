#pragma once
#include"head.h"
#include "basic.h"
#include "role.h"
enum  ITEM_OR_MONSTER
{
	ITEM = 0x1 << 1,
	MONSTER = 0x1 << 2,
};
class CGameApp
{
public:
	int I_dialog[10] = {0};									//�Ի�˳��
	int keyboard;										//�������µ�ֵ
	int Collision_Item_or_Monster;						//��ײ������
	bool WhetherKey = false;							//�������Ƿ�����
	CMapManager C_MapManager;							//���йؿ���ͼ����������
	CBasic C_CBasic;									//�洢���еĻ�������
	CPerson C_PersonObj;								//����
	void initGame();								//��ʼ��
	void MyDraw();									//����
	int Collision();			//����Ƿ�����ײ 1�ǵ�ͼ��2�ǹ��4�ǵ���
	bool combat();									//�����ս��
	void GamePlay();								//��Ϸ�淨
	int UseItem();									//ʹ�õ���
	int dialog();									//�Ի�
};

