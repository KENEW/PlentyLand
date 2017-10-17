#pragma once
//#include "stdafx.h"
#include "Manager.h"

enum UiCondition
{
	NONE, DOWN, UP, DCLICK
};

class CInterfaceManager : public CManager<CInterfaceManager, vector<void(*)(void)>, WPARAM>
{
private:
	string PressString;
	bool GetChar;

public:
	int MouseX, MouseY;
	UiCondition MouseWheelDirection;
	UiCondition LMouseCondition;
	UiCondition RMouseCondition;
	UiCondition KeyCondition;
	bool isMouseMove;

public:
	CInterfaceManager();
	~CInterfaceManager();

	void StateInitalize();

	void StartGetPressKey();
	string GetPressKey();
	void EreasePressKey();
	void EndGetPressKey();	

	void KeyCheckFunc(WPARAM key);
};
#define UI_GET CInterfaceManager::GetInstance()
