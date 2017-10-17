#include "stdafx.h"
#include "System.h"

//////////////////////////////////////////////////////////////////////////
// 프로젝트 명 : SurGameBase
// 업데이트 날짜 : 2017.10.17
// 업데이트 목록
// - ver 1.0 글씨 출력 가능(Direct x), 콘솔 사용, 소리 사용(fmod)
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
