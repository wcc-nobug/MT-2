#include "Graphic.h"

#pragma comment(lib,"../../common/DX/lib/d3d9.lib")
#pragma comment(lib,"../../common/DX/lib/d3dx9.lib")

HWND CGraphic::InitWindow(pMainWndProc proc,WORD width,WORD height,TSTRING titelName,TSTRING className)
{
	//1�����崰����
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = proc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = className.c_str();//��һ������

	//2��ע�ᴰ����
	if (!RegisterClass(&wc))
	{
		MessageBox(0, _T("RegisterClass Failed."), 0, 0);
		return nullptr;
	}

	// Compute window rectangle dimensions based on requested client area dimensions.
	RECT R = { 0, 0, width, height };
	AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
	int newwidth = R.right - R.left;
	int newheight = R.bottom - R.top;

	//3����������
	m_hMainWnd = CreateWindow(className.c_str(), titelName.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, newwidth, newheight, 0, 0, 0, 0);
	if (!m_hMainWnd)
	{
		MessageBox(0, _T("CreateWindow Failed."), 0, 0);
		return nullptr;
	}

	//4����ʾ����
	ShowWindow(m_hMainWnd, SW_SHOW);

	//5�����´���
	UpdateWindow(m_hMainWnd);

	return m_hMainWnd;
}

void CGraphic::InitDX(HWND hwnd)
{
	m_hMainWnd = hwnd;

	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	
	//Ĭ���Կ�
	//ʹ���Կ��ļ��ٹ���
	//���ھ��
	//ʹ��Ӳ�����ٴ�����
	D3DPRESENT_PARAMETERS d3dpp;//�����̨������������
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;//����֧��ȫ��
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;//32λ��ɫ
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;//ǰ��̨�Ľ�����ʽΪ����
	//������ȵĸ�ʽ�ͼ�����ȼ���
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24X8;//������Ȼ���ľ��ȣ�8��16��24��32��
	d3dpp.EnableAutoDepthStencil = true;
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hMainWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &m_pDevice);

	if (!m_pDevice)
		return;
	////�Ƚ���ȣ����в��ԣ���ͬ�����꣬���ֵС��ͨ�����ԣ�����Ƴ�����
	//m_pDevice->SetRenderState(D3DRS_ZENABLE, true);//������Ȳ���
	//m_pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);//С��ͨ������

	D3DXCreateSprite(m_pDevice, &m_pSprite);

	D3DXCreateLine(m_pDevice, &m_pLine);

	D3DXCreateFont(m_pDevice, 0,0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, _T("����"), &m_pFont);

}

HRESULT CGraphic::LoadTex(LPCTSTR fileName, MyImageInfo& info,DWORD color)
{
	if (FAILED(D3DXCreateTextureFromFileEx(m_pDevice, fileName, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, 0, color, 0, 0, &info.pTex)))
	{
		info.pTex = nullptr;
		return E_FAIL;
	}
	D3DSURFACE_DESC desc;
	info.pTex->GetLevelDesc(0, &desc);
	info.width = desc.Width;
	info.height = desc.Height;

	return S_OK;
}

void CGraphic::BeginDraw()
{
	if (m_pDevice)
	{
		//��գ���ɫ����target����Ȼ��棩
		m_pDevice->Clear(0, 0, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(128, 128, 128), 1, 0);

		m_pDevice->BeginScene();
	}
}

void CGraphic::EndDraw()
{
	m_pDevice->EndScene();

	//չ�ֵ���Ļ��
	m_pDevice->Present(0, 0, 0, 0);
}

void CGraphic::CloseDX()
{

}
void CGraphic::DrawTex(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 srcPos, D3DXVECTOR2 size, D3DXVECTOR3 pos, D3DXVECTOR3 center /*= D3DXVECTOR3(0.0f, 0, 0)*/, D3DXVECTOR3 rot /*= D3DXVECTOR3(0.0f, 0, 0)*/, D3DXVECTOR3 scale /*= D3DXVECTOR3(0.0f, 0, 0)*/)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc = { srcPos.x,srcPos.y,srcPos.x+size.x,srcPos.y+size.y };

	D3DXMATRIX matWorld, matT, matR, matS;
	D3DXMatrixTranslation(&matT, pos.x, pos.y, pos.z);
	D3DXMatrixRotationZ(&matR, rot.z);
	D3DXMatrixScaling(&matS, scale.x, scale.y, scale.z);
	matWorld = matS * matR * matT;
	m_pSprite->SetTransform(&matWorld);

	m_pSprite->Draw(tex, &rc, &center, nullptr, 0xffffffff);

	m_pSprite->End();
}
void CGraphic::DrawTex(MyImageInfo& info, D3DXVECTOR3 pos, D3DXVECTOR3 center /*= D3DXVECTOR3(0.0f, 0, 0)*/, D3DXVECTOR3 rot /*= D3DXVECTOR3(0.0f, 0, 0)*/, D3DXVECTOR3 scale /*= D3DXVECTOR3(0.0f, 0, 0)*/)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc = {0,0,info.width,info.height};
	D3DXMATRIX matWorld, matT, matR, matS;
	D3DXMatrixTranslation(& matT, pos.x, pos.y, pos.z);





	
	D3DXMatrixRotationZ(&matR, rot.z);
	D3DXMatrixScaling(&matS, scale.x, scale.y, scale.z);

	matWorld = matS * matR * matT;
	m_pSprite->SetTransform(&matWorld);
	if(info.pTex)
		m_pSprite->Draw(info.pTex, &rc, &center, nullptr, 0xffffffff);

	m_pSprite->End();
}

void CGraphic::DrawText(TSTRING text, RECT rc,DWORD style,DWORD color)
{
	m_pFont->DrawText(nullptr, text.c_str(), _tcslen(text.c_str()), &rc, style,color);
}
