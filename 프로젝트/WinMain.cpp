#include "stdafx.h"
#include "System.h"

//////////////////////////////////////////////////////////////////////////
// ������Ʈ �� : SurGameBase
// ������Ʈ ��¥ : 2017.10.17
// ������Ʈ ���
// - ver 1.0 �۾� ��� ����(Direct x), �ܼ� ���, �Ҹ� ���(fmod)
//////////////////////////////////////////////////////////////////////////
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
#ifdef _DEBUG
	AllocConsole();
	freopen("CONIN$", "rb", stdin);
	freopen("CONOUT$", "wb", stdout);
#endif

	SYS_GET->Initialize();

	SYS_GET->Run();

	SYS_GET->Release();

	return 0;
}
