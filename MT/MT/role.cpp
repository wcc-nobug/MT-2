#include "role.h"
#include "Tool.h"

void CPerson::initPerson()//��ʼ������
{
	CTool::GetFile(L"../bin/data/role.txt", this, FIGUREMDATA);
	for (int i=0;i<16;i++)
	{
		TSTRING buf = L"../bin/roleImage/role_";
		TSTRING buf2 = to_wstring(i);
		TSTRING buf3 = L".png";
		buf = buf + buf2 + buf3;
		CGraphic::GetSingleObjPtr()->LoadTex(buf.c_str(), this->PersonPhoto[i], 0xFFFFFFFF);
	}
}



void CPerson::PersonMove(D3DXVECTOR3 pos)//�����ƶ�
{
	this->PersonPos += pos;
}

