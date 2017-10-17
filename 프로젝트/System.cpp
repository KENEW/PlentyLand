#include "stdafx.h"
#include "System.h"


CSystem::CSystem()
{
}


CSystem::~CSystem()
{
}

bool CSystem::Initialize()
{
	CWindowBase::Initialize();
	CWindowBase::WindowMode();

	return 1;
}

void CSystem::RenderStart()
{
	g_d3dDev->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_d3dDev->BeginScene();
}

void CSystem::RenderEnd()
{
	g_d3dDev->EndScene();
	g_d3dDev->Present(0, 0, 0, 0);
}


void CSystem::Run()
{
	MSG msg;
	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			GetMessage(&msg, NULL, 0, 0);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update();
		}
	}
}


void CSystem::Update()
{
	SCENE_GET->mScene->Process();

	RenderStart();

	SCENE_GET->mScene->Render();

	RenderEnd();

	TIME_GET->Update();
}

void CSystem::Release()
{
	TIME_GET->Release();
	UI_GET->Release();
}
