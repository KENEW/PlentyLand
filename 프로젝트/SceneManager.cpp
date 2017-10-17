#include "stdafx.h"
#include "SceneManager.h"


CSceneManager::CSceneManager()
	: NextScene(NONE)
{
	mScene = new CTestScene;
}


CSceneManager::~CSceneManager()
{

}

void CSceneManager::SetNextScene(SceneNum Scene)
{
	NextScene = Scene;
}

void CSceneManager::ChangeScene()
{
	if (NextScene != SceneNum::NONE)
	{
		DELETE_S(mScene);

		switch (NextScene)
		{
		case TEST_SCENE:
			mScene = new CTestScene;
			break;
		case NONE:
		default:
			ERROR_CHECK(true, "NoScene");
			break;
		}
		
		NextScene = SceneNum::NONE;
	}
}

void CSceneManager::Release()
{
	DELETE_S(mScene);
}