#pragma once
#include "WindowBase.h"
#include "Singleton.h"

class CSystem : public CSingleton<CSystem>, public CWindowBase
{
public:
	CSystem(void);
	~CSystem(void);

private:
	void Update();

public:
	void RenderStart();
	void RenderEnd();

	bool Initialize();
	void Run();
	void Release();
};
#define SYS_GET CSystem::GetInstance()



