#include "stdafx.h"
#include "WindowBase.h"

CWindowBase::CWindowBase()
{
}


CWindowBase::~CWindowBase()
{
	RELEASE(g_d3dDev);
	DELETE_S(g_d3dDev);

	RELEASE(g_d3d);
	DELETE_S(g_d3d);
}

LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	UI_GET->StateInitalize();
	switch (message)
	{
	case WM_MOUSEMOVE:
		UI_GET->isMouseMove = true;
		UI_GET->MouseX = LOWORD(lParam);
		UI_GET->MouseY = HIWORD(lParam);
		break;
	case WM_MOUSEWHEEL:
		if (HIWORD(wParam) == 120)
		{
			UI_GET->MouseWheelDirection = UiCondition::UP;		// 회전 각도
		}
		else
		{
			UI_GET->MouseWheelDirection = UiCondition::DOWN;	// 회전 각도
		}
		printf("%d\n", HIWORD(wParam));
		break;
	case WM_LBUTTONDOWN:
		UI_GET->LMouseCondition = UiCondition::DOWN;
		break;
	case WM_LBUTTONDBLCLK:
		UI_GET->LMouseCondition = UiCondition::DCLICK;
		break;
	case WM_LBUTTONUP:
		UI_GET->LMouseCondition = UiCondition::UP;
		break;
	case WM_RBUTTONDOWN:
		UI_GET->RMouseCondition = UiCondition::DOWN;
		break;
	case WM_RBUTTONDBLCLK:
		UI_GET->RMouseCondition = UiCondition::DCLICK;
		break;
	case WM_RBUTTONUP:
		UI_GET->RMouseCondition = UiCondition::UP;
		break;
	case WM_KEYDOWN:
		UI_GET->KeyCondition = UiCondition::DOWN;
		UI_GET->KeyCheckFunc(wParam);
		break;
	case WM_KEYUP:
		UI_GET->KeyCondition = UiCondition::UP;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool CWindowBase::Initialize(char* winName)
{
	WNDCLASSEX wcex;
	wchar_t title[120];

	int end;
	end = MultiByteToWideChar(CP_ACP, 0, winName, strlen(winName), title, sizeof(title));
	title[end] = 0;
	//mbstowcs(title, winName, strlen(winName));

	wcex.cbSize = sizeof(WNDCLASSEX);

	m_hInst = GetModuleHandle(NULL);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)StaticWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = NULL;
	wcex.hCursor = NULL;
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = title;
	wcex.hIconSm = NULL;

	ERROR_CHECK(!RegisterClassEx(&wcex), "RegisterClassEx() - FAILED");

	m_hWnd = CreateWindowEx(WS_EX_TOPMOST, title, title,
		WS_BORDER | WS_CAPTION | WS_SYSMENU,
		0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL, NULL,
		m_hInst,
		NULL);

	ERROR_CHECK(!m_hWnd, "CreateWindow() - FAILED");

	WindowMode();

	g_d3d = Direct3DCreate9(D3D_SDK_VERSION);

	ERROR_CHECK(!g_d3d, "Direct3DCreate9() - FAILED");

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;

	g_d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_d3dDev);

	ERROR_CHECK(!g_d3dDev, "CreateDevice() - FAILED");

	g_d3dDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	g_d3dDev->SetRenderState(D3DRS_ZENABLE, true);

	return TRUE;
}

//void CWindowBase::Terminate()
//{
//
//}

bool CWindowBase::WindowMode()
{
	//m_hInst = GetModuleHandle(NULL);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}