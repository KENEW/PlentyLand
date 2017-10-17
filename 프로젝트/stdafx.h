#pragma once

#define WIN32_LEAN_AND_MEAN
//Windows Header
#include <Windows.h>
#include <MMSystem.h>
#include <CommDlg.h>

//ǥ�� C Header
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#pragma warning(disable : 4996)
#include <strsafe.h>
#pragma warning(default : 4996)

//ǥ�� C++ Header
#include <string>
#include <vector>
#include <map>

//FMOD Header
#include <fmod.h>

//DirectX Header
#include <d3d9.h>
#include <d3dx9.h>

//��ũ�� ����
#include "Core.h"

// ����� ���� Header

// Parent
#include "Singleton.h"
#include "WindowBase.h"
#include "Manager.h"
#include "Object.h"
#include "Scene.h"

// Manager
#include "InterfaceManager.h"
#include "TimeManager.h"
#include "TextrueManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"

// Child (or no inherit)
#include "System.h"

// Scene
#include "TestScene.h"

