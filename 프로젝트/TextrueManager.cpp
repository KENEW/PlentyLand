#include "stdafx.h"
#include "TextrueManager.h"

CTextureManager::CTextureManager()
{
	D3DXCreateSprite(SYS_GET->g_d3dDev, &g_d3dSpr);
}

CTextureManager::~CTextureManager()
{
	RELEASE(g_d3dSpr);
	DELETE_S(g_d3dSpr);
}

LPDIRECT3DTEXTURE9 CTextureManager::LoadTexture(string path)
{
	if (isExist(path))
	{
		return data[path]->Texture;
	}
	else
	{
		AddTexture(path);
	}
	
	return LoadTexture(path);
}

D3DXIMAGE_INFO CTextureManager::LoadImageInfo(string path)
{
	if (isExist(path))
	{
		return data[path]->ImageInfo;
	}
	else
	{
		AddTexture(path);
	}

	return LoadImageInfo(path);
}

void CTextureManager::AddTexture(string path)
{
	TextureInfo* Info = new TextureInfo;

	ERROR_CHECK(D3DXCreateTextureFromFileExA(SYS_GET->g_d3dDev, path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		1,
		1,
		NULL,
		&Info->ImageInfo,
		NULL,
		&Info->Texture) != D3D_OK, "Load_Texture() - FAILED");

	Add(Info, path);
}

void CTextureManager::RenderObj(CObject* obj)
{
	if (obj->Visible)
	{
		RECT size = { 0, 0, (LONG)obj->mSize.x, (LONG)obj->mSize.y };

		float Degree = D3DXToRadian(obj->Degree);

		D3DXMATRIX MAT;

		D3DXMATRIX Rot;
		D3DXMATRIX Move;
		D3DXMATRIX Center;
		D3DXMATRIX Center2;
		D3DXMATRIX Scale;

		D3DXMatrixIdentity(&MAT);
		D3DXMatrixIdentity(&Rot);
		D3DXMatrixIdentity(&Move);
		D3DXMatrixIdentity(&Center);
		D3DXMatrixIdentity(&Center2);

		D3DXMatrixRotationZ(&Rot, Degree);

		D3DXMatrixInverse(&Center2, NULL, &Center);

		D3DXMatrixTranslation(&Center2, -obj->mSize.x, -obj->mSize.y, 0);
		D3DXMatrixTranslation(&Move, obj->mPos.x + obj->mSize.x, obj->mPos.y + obj->mSize.y, 0);
		D3DXMatrixScaling(&Scale, obj->mScale.x, obj->mScale.y, 1);

		MAT = Center2 * Rot * Center * Scale * Move;

		g_d3dSpr->SetTransform(&MAT);

		g_d3dSpr->Begin(D3DXSPRITE_ALPHABLEND);
		g_d3dSpr->Draw(obj->mTexture, &size, NULL, NULL, 0xffffffff);

		g_d3dSpr->End();
	}
}

void CTextureManager::Release()
{
	RELEASE(g_d3dSpr);
	CManager::Release();
}
