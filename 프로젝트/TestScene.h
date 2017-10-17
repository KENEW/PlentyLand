#pragma once
#include "Scene.h"
class CTestScene :
	public CScene
{
public:
	CTestScene();
	~CTestScene();

public:
	CObject* Test;

	void Process();
	void Render();
};

