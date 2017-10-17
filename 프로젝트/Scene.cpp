#include "stdafx.h"
#include "Scene.h"

CScene::CScene()
{
}


CScene::~CScene()
{
	TEXTURE_GET->Release();
	OBJ_GET->Release();
	TIME_GET->Release();
}
