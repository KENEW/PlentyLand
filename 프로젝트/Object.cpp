#include "stdafx.h"
#include "Object.h"

CObject::CObject(string path, D3DXVECTOR3 pos, float Degree, D3DXVECTOR3 scale)
	: Degree(Degree), Frame(0), Visible(true),
	mPos(pos), mSize(0, 0, 1), mScale(scale)
{
	if (path != "")
	{
		LoadTexture(path);
	}	
	OBJ_GET->AddObject(this, (int)this);
}

CObject::~CObject()
{
	DELETE_S(mTexture);
}

void CObject::LoadTexture(string path)
{
	mTexture = TEXTURE_GET->LoadTexture(path);
	LoadImageInfo(path);
	SettingSize();
}

void CObject::LoadImageInfo(string path)
{
	mImageInfo = TEXTURE_GET->LoadImageInfo(path);
}

void CObject::SettingSize()
{
	mSize = { (float)mImageInfo.Width, (float)mImageInfo.Height, 1 };
}

D3DXVECTOR3 CObject::GetImageSize()
{
	return{ (float)mImageInfo.Width, (float)mImageInfo.Height, 1 };
}

bool CObject::Animation(string path, int Frame, float Delay, bool SizeKeeping)
{
	if (TIME_GET->CheckTick(to_string((int)this) + path, true, Delay))
	{
		if (Frame == Frame)
		{
			Frame = 0;
			return true;
		}

		Frame++;

		char buffer[128];
		sprintf(buffer, "%04d", Frame);
		path += buffer;
		path += ".png";
		LoadTexture(path);
	}
	return false;
}