#include "stdafx.h"
#include "ObjectManager.h"

CObjectManager::CObjectManager()
{
}


CObjectManager::~CObjectManager()
{
}

void CObjectManager::AddObject(CObject* obj, int Address)
{
	Add(obj, Address);
}

void CObjectManager::RenderAllObj()
{
	CONTAINER_LOOP(iter, data)
	{
		if (iter->second != nullptr)
		{
			TEXTURE_GET->RenderObj(iter->second);
		}
	}
}
