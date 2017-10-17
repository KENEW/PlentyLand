#pragma once
#include "Manager.h"
class CSceneManager :
	public CSingleton<CSceneManager>
{
public:
	enum SceneNum
	{
		NONE, TEST_SCENE
	};

	CScene * mScene;
	SceneNum NextScene;

public:
	CSceneManager();
	~CSceneManager();

public:
	void SetNextScene(SceneNum Scene);
	void ChangeScene();
	void Release();
};
#define SCENE_GET CSceneManager::GetInstance()

