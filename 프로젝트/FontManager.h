#pragma once
#include "Manager.h"
class CFontManager
	: public CSingleton<CFontManager>
{
private:
	LPD3DXFONT g_d3dFont;

public:
	CFontManager();
	~CFontManager();

public:
	void SetFont(string font, int size);
	void Output(string str, int x, int y, D3DCOLOR c = D3DCOLOR_XRGB(0, 0, 0));
};
#define FONT_GET CFontManager::GetInstance()
