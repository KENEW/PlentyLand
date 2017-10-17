#pragma once
#include "Object.h"
class CWindowBase
{
public:
	HWND	m_hWnd;
	HINSTANCE m_hInst;

	LPDIRECT3D9 g_d3d;
	LPDIRECT3DDEVICE9 g_d3dDev;

	//LPD3DXFONT g_d3dFont;

public:
	CWindowBase();
	virtual ~CWindowBase();

	__inline HWND GetHandle() const { return m_hWnd; };
	__inline HINSTANCE GetHInstace() const { return m_hInst; };
	bool Initialize(char* winName = "SurGameEngine");

	//void Terminate();
	bool WindowMode();
};


