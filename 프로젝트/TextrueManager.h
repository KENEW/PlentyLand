#pragma once
#include "Manager.h"

struct TextureInfo
{
	~TextureInfo()
	{
		DELETE_S(Texture);
	}

	LPDIRECT3DTEXTURE9 Texture;
	D3DXIMAGE_INFO ImageInfo;
};

class CTextureManager :
	public CManager<CTextureManager, TextureInfo, string>
{
public:
	LPD3DXSPRITE g_d3dSpr;

public:
	CTextureManager();
	~CTextureManager();

public:
	LPDIRECT3DTEXTURE9 LoadTexture(string path);
	D3DXIMAGE_INFO LoadImageInfo(string path);

	void AddTexture(string path);

	void RenderObj(CObject* obj);
	void Release();
};
#define TEXTURE_GET CTextureManager::GetInstance()


