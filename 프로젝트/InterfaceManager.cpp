#include "stdafx.h"
#include "InterfaceManager.h"


CInterfaceManager::CInterfaceManager()
	: GetChar(false), PressString(""), MouseX(0), MouseY(0), MouseWheelDirection(NONE)
	, LMouseCondition(NONE), RMouseCondition(NONE), KeyCondition(NONE),
	isMouseMove(false)
{
}

CInterfaceManager::~CInterfaceManager()
{
	map<WPARAM, vector<void(*)(void)>*>::iterator iter;
	CONTAINER_LOOP(iter, data)
	{
		iter->second->clear();
	}
}

void CInterfaceManager::StateInitalize()
{
	MouseX = MouseY = 0;
	MouseWheelDirection = LMouseCondition = RMouseCondition = KeyCondition = NONE;
	isMouseMove = false;
}

void CInterfaceManager::StartGetPressKey()
{
	GetChar = true;
}

string CInterfaceManager::GetPressKey()
{
	return PressString;
}

void CInterfaceManager::EreasePressKey()
{
	PressString = "";
}

void CInterfaceManager::EndGetPressKey()
{
	GetChar = false;
}

void CInterfaceManager::KeyCheckFunc(WPARAM key)
{
	if (isExist(key))
	{
		vector<void(*)(void)>::iterator iter;
		CONTAINER_LOOP(iter, (*data[key]))
		{
			(*iter)();
		}
	}
}
