#pragma once
// #include "common.h"
// #include "Singleton.h"
#include "head.h"

struct MyImageInfo
{
	LPDIRECT3DTEXTURE9 pTex;//�����ͼƬ
	WORD width;//ͼƬ�Ŀ��
	WORD height;//ͼƬ�ĸ߶�
};

//����ָ��-----ר������������Ϣ�ĺ��������ھ������Ϣ���ͣ���Ϣ����ֵ1����Ϣ�ĸ���ֵ2��
typedef LRESULT(*pMainWndProc)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class CGraphic :
    public CSingleton<CGraphic>
{
    friend CSingleton<CGraphic>;

public:
	HWND InitWindow(pMainWndProc proc, WORD width=800, WORD height=600, TSTRING titelName=_T("Game"), TSTRING className=_T("MyClass"));
	void InitDX(HWND hwnd);
	HRESULT LoadTex(LPCTSTR fileName, MyImageInfo& info,DWORD color=0xff000000);
	void BeginDraw();
	void EndDraw();
	void CloseDX();
	void DrawTex(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 srcPos, D3DXVECTOR2 size, D3DXVECTOR3 pos, D3DXVECTOR3 center = D3DXVECTOR3(0.0f, 0, 0), D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0, 0), D3DXVECTOR3 scale = D3DXVECTOR3(1.0f, 1, 1));
	void DrawTex(MyImageInfo& info, D3DXVECTOR3 pos, D3DXVECTOR3 center = D3DXVECTOR3(0.0f, 0, 0), D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0, 0), D3DXVECTOR3 scale = D3DXVECTOR3(1.0f, 1, 1));

	void DrawText(TSTRING text, RECT rc, DWORD style=DT_LEFT|DT_TOP, DWORD color=0xffff0000);//Ĭ�����϶���ĺ�ɫ����

	LPDIRECT3DDEVICE9 m_pDevice;//DX�豸�ӿ�---�����Կ��豸

private:
	LPDIRECT3DTEXTURE9 m_pTex;//ͼƬ�ӿ�
	IDirect3D9* m_pD3D;
	//LPDIRECT3D9 m_pD3D;//DX��ڽӿ�
	
	LPD3DXLINE m_pLine;//���ߵĽӿ�
	LPD3DXSPRITE m_pSprite;//��2Dͼ�εĽӿ�
	LPD3DXFONT m_pFont;//�������ֵĽӿ�
	HWND m_hMainWnd;//���ھ��
};

