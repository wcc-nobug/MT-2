#include "head.h"
#include "Tool.h"
#include "Monster.h"
#include "Item.h"
#include "Map.h"
#include "GameApp.h"
#include "Graphic.h"

CGameApp* P_GameApp = new CGameApp;
//ר����������ǰ��Ϸ���ڵ���Ϣ���������ھ������Ϣ���ͣ���Ϣ����ֵ1����Ϣ�ĸ���ֵ2��
LRESULT MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);//�˳���Ϣ
		break;
	}

	case WM_KEYDOWN:
	{
		
		switch (wParam)
		{
		case VK_LEFT:
			P_GameApp->keyboard = KEY_LEFT;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ -18.5f, 0.0f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//����Ƿ���ײ
			break;
		case VK_UP:
			P_GameApp->keyboard = KEY_UP;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ 0.0f, -18.5f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//����Ƿ���ײ
			break;
		case VK_RIGHT:
			P_GameApp->keyboard = KEY_RIGHT;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ 18.5f, 0.0f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//����Ƿ���ײ
			break;
		case VK_DOWN:
			P_GameApp->keyboard = KEY_DOWN;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ 0.0f, 18.5f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//����Ƿ���ײ
			break;
		case VK_SPACE:
			switch (P_GameApp->C_MapManager.level)
			{
			case 0:
				for (auto it = P_GameApp->C_MapManager.V_CMap[P_GameApp->C_MapManager.level].L_CMapItem.begin(); it != P_GameApp->C_MapManager.V_CMap[P_GameApp->C_MapManager.level].L_CMapItem.end();it++)
				{
					if ((*it)->ID==1030)
					{
						float x, y, z;
						x = (*it)->pos.X*37;
						y= (*it)->pos.Y * 37;
						z = 0.0f;
						if (CTool::Collision(P_GameApp->C_PersonObj.NewPersonPos,{x,y,z},37.0f,37.0f))
						{
							P_GameApp->I_dialog[0] += 1;
							break;
						}
					}
					
				}
				
			}
			
		}
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);


}

//������
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//��ʼ����Ϸ����
	HWND myHwnd = CGraphic::GetSingleObjPtr()->InitWindow(MainWndProc, 800, 407, _T("DXImageProj"), _T("DXImageProj"));
	CGraphic::GetSingleObjPtr()->InitDX(myHwnd);	//��ʼ��ͼ�ο�

	P_GameApp->initGame();	//��Ϸ��ʼ��
	P_GameApp->C_MapManager.level = 0;
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)//�˳���Ϸѭ��
			{
				break;
			}
			TranslateMessage(&msg);

			DispatchMessage(&msg);
		}
		CGraphic::GetSingleObjPtr()->BeginDraw();//˫�����ͼ

		P_GameApp->MyDraw();//����
		P_GameApp->GamePlay();//��Ϸ�淨

		CGraphic::GetSingleObjPtr()->EndDraw();


		Sleep(30);
	}

}
//����¥�ݺ�����λ�ñ仯
// 			for (auto it=P_GameApp->C_MapManager.V_CMap[P_GameApp->C_MapManager.level].L_CMapItem.begin(); it != P_GameApp->C_MapManager.V_CMap[P_GameApp->C_MapManager.level].L_CMapItem.end();it++)
// 			{
// 				if (it->ID==1008)
// 				{
// 					COORD temp =it->gte();
// 					float x = temp.X * 37;
// 					float y = temp.Y * 37;
// 					P_GameApp->C_PersonObj.PersonPos = { x,y,0.0f };
// 				}
// 			}