#pragma once

// 공통 정의 및 매크로 함수 정의

// 공통 정의
#define PI	(3.141592f)
#define MAX_TEXTURE	(64)
#define MAX_STRING  (256)
#define WINDOW_WIDTH	(1280)
#define WINDOW_HEIGHT	(768)
#define WINDOW_BITCOUNT (4)	//byte
#define FPS_DEFAULT		(60.0f)
#define TRASH_VAL	(-777)
#define CURRENT_SEC (double)(GetTickCount64() / 1000.0)
#define SOUND_MAX 6

// 매크로 함수
#define ERROR_CHECK(what, message) if(what) {MessageBoxA(0, message, "ERROR!!", 0); exit(0);}
#define DELETE_S(ptr) if(!ptr) { delete ptr; ptr = nullptr; }
#define CONTAINER_LOOP(iterator, container)	for (auto iterator = container.begin(); iterator != container.end(); iterator++)
#define RELEASE(obj) obj->Release();

//#define GET_INST(singleton) singleton::GetInstance()

using namespace std;