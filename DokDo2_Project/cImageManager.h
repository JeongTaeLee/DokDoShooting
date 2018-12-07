#pragma once

#include "singleton.h"

struct texture
{
public:
	LPDIRECT3DTEXTURE9	lpTexture;	
	D3DXIMAGE_INFO		info;

public:
	texture(LPDIRECT3DTEXTURE9 _lpTexture, D3DXIMAGE_INFO _info)
		:lpTexture(_lpTexture), info(_info)
	{}
	~texture(){}

	void Render(float x, float y, float size = 1.0f, float rot = 0.0f, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(float x, float y, float size, float rot, D3DXVECTOR3 center, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(float x, float y, float size, float rot, D3DXVECTOR3 center, RECT srcRect, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	void CenterRender(float x, float y, float size = 1.0f, float rot = 0.0f, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

};


class cImageManager : public singleton<cImageManager>
{
private:
	LPD3DXSPRITE m_sprite;

	map<string, texture*> m_singleImage;
	map<string, vector<texture* > * > m_listImage;

	void Init();
	void Release();
public:
	cImageManager();
	virtual ~cImageManager();

	void Begin();
	void End();

	texture * AddSingleImage(const string & key, const string & path);
	vector<texture*> * AddListImage(const string & key, const TCHAR * path, int count);

	texture *			FindSingleImage(const string & key);
	vector<texture*> *	FindListImage(const string & key);
	
	void DeleteListImage(const string & key);
	void DeleteSingleImage(const string & key);

	void Render(texture* _lpTexture, float x, float y, float size = 1.0f, float rot = 0.0f, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(texture* _lpTexture, float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(texture* _lpTexture, float x, float y, float size, float rot, D3DXVECTOR3 center, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(texture* _lpTexture, float x, float y, float size, float rot, D3DXVECTOR3 center, RECT srcRect, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	void CenterRender(texture * _lpTexture, float x, float y, float size = 1.0f, float rot = 0.0f, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(texture * _lpTexture, float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	void ResetDevice() { m_sprite->OnResetDevice(); };
	void LostDevice() { m_sprite->OnLostDevice(); };
};

#define IMAGEMANAGER cImageManager::GetInstance()