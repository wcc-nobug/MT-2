#include "head.h"
#include "Tool.h"
#include "Monster.h"
#include "Item.h"
#include "Map.h"
#include "GameApp.h"
#include "Graphic.h"

CGameApp* P_GameApp = new CGameApp;
//专门用来处理当前游戏窗口的消息函数（窗口句柄，消息类型，消息附加值1，消息的附加值2）
LRESULT MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);//退出消息
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
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//检测是否碰撞
			break;
		case VK_UP:
			P_GameApp->keyboard = KEY_UP;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ 0.0f, -18.5f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//检测是否碰撞
			break;
		case VK_RIGHT:
			P_GameApp->keyboard = KEY_RIGHT;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ 18.5f, 0.0f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//检测是否碰撞
			break;
		case VK_DOWN:
			P_GameApp->keyboard = KEY_DOWN;
			P_GameApp->WhetherKey = true;
			P_GameApp->C_PersonObj.NewPersonPos.operator+=({ 0.0f, 18.5f, 0.0f });
			P_GameApp->Collision_Item_or_Monster = P_GameApp->Collision();//检测是否碰撞
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

//主函数
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//初始化游戏窗口
	HWND myHwnd = CGraphic::GetSingleObjPtr()->InitWindow(MainWndProc, 800, 407, _T("DXImageProj"), _T("DXImageProj"));
	CGraphic::GetSingleObjPtr()->InitDX(myHwnd);	//初始化图形库

	P_GameApp->initGame();	//游戏初始化
	P_GameApp->C_MapManager.level = 0;
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)//退出游戏循环
			{
				break;
			}
			TranslateMessage(&msg);

			DispatchMessage(&msg);
		}
		CGraphic::GetSingleObjPtr()->BeginDraw();//双缓冲绘图

		P_GameApp->MyDraw();//绘制
		P_GameApp->GamePlay();//游戏玩法

		CGraphic::GetSingleObjPtr()->EndDraw();


		Sleep(30);
	}

}
//碰到楼梯后人物位置变化
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