#include "stdafx.h"
#include "TestScene.h"


CTestScene::CTestScene()
{
	TIME_GET->AddTick("Test", 1.0f);
	Test = new CObject("Resource/Image/hero_sprites.png");
}


CTestScene::~CTestScene()
{
}


void CTestScene::Process()
{
	printf("%f\n", TIME_GET->GetTick("Test"));
}

void CTestScene::Render()
{
	OBJ_GET->RenderAllObj();
}
