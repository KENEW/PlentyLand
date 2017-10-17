#include "stdafx.h"
#include "FontManager.h"

CFontManager::CFontManager()
{
	g_d3dFont = nullptr;
}

CFontManager::~CFontManager()
{
	RELEASE(g_d3dFont);
	DELETE_S(g_d3dFont);
}

void CFontManager::SetFont(string font, int size)
{
	HRESULT hr = D3DXCreateFontA(SYS_GET->g_d3dDev,
		size,     // Height
		0,     // Width
		FW_NORMAL,   // Weight
		1,     // MipLevels, 0 = autogen mipmaps
		0,     // Italic
		DEFAULT_CHARSET, // CharSet
		0,     // OutputPrecision
		0,     // Quality
		0,     // PitchAndFamily
		font.c_str(),  // pFaceName
		&g_d3dFont);  // ppFont
}

void CFontManager::Output(string str, int x, int y, D3DCOLOR c)
{
	RECT pos = { x, y, 0, 0 };

	TEXTURE_GET->g_d3dSpr->Begin(D3DXSPRITE_ALPHABLEND);
	g_d3dFont->DrawTextA(
		NULL,        // ��������Ʈ �ּ�.
		str.c_str(),      //�׸����� �ϴ� ���ڿ�
		-1,       //NULL�� ������ ���ڿ�
		&pos,     //�ؽ��İ� �׷��� �簢��
		DT_NOCLIP,      //�簢���� ���� ��ܿ� �׸���.
		c);  //���ڻ�

	TEXTURE_GET->g_d3dSpr->End();
}
