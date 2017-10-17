#pragma once
class CObject
{
public:
	LPDIRECT3DTEXTURE9 mTexture;
	D3DXIMAGE_INFO mImageInfo;
	D3DXVECTOR3 mPos;
	D3DXVECTOR3 mSize;
	D3DXVECTOR3 mScale;

	float Degree;
	bool Visible;

	int Frame;

public:
	CObject(string path = "", D3DXVECTOR3 pos = { 0, 0, 0 }, float Degree = 0
		, D3DXVECTOR3 scale = { 1, 1, 1 });
	~CObject();

public:
	void LoadTexture(string path);
	void LoadImageInfo(string path);

	void SettingSize();

	D3DXVECTOR3 GetImageSize();

	bool Animation(string path, int Frame, float Delay, bool SizeKeeping = false);
};

