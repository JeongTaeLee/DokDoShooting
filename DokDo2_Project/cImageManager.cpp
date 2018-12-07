#include <DXUT.h>
#include "cImageManager.h"
#include "MyLib.h"

LPD3DXSPRITE g_sprite;

void cImageManager::Init()
{
	if (FAILED(D3DXCreateSprite(g_Device, &m_sprite)))
	{
		MessageBox(nullptr, TEXT("Error : FAILED Create Is sprite"), TEXT("Error"), MB_OK);
		exit(-1);
	}
	g_sprite = m_sprite;
}

void cImageManager::Release()
{
	for (auto Iter : m_singleImage)
	{
		Iter.second->lpTexture->Release();
		SAFE_DELETE(Iter.second);
	}
	m_singleImage.clear();

	for (auto Iter : m_listImage)
	{
		for (auto Iter02 : (*Iter.second))
		{
			Iter02->lpTexture->Release();
			SAFE_DELETE(Iter02);
		}
		(*Iter.second).clear();
		SAFE_DELETE(Iter.second);
	}

	m_listImage.clear();

	m_sprite->Release();
}

cImageManager::cImageManager()
{
	Init();
}

cImageManager::~cImageManager()
{
	Release();
}

void cImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void cImageManager::End()
{
	m_sprite->End();
}

texture * cImageManager::AddSingleImage(const string & key, const string & path)
{

	auto find = m_singleImage.find(key);

	if (find == m_singleImage.end())
	{
		LPDIRECT3DTEXTURE9	_lpTexture;
		D3DXIMAGE_INFO		_info;

		if (D3DXCreateTextureFromFileExA(g_Device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &_info,
			nullptr, &_lpTexture) == S_OK)
		{
			texture * lpTemp = new texture(_lpTexture, _info);

			m_singleImage.insert(make_pair(key, lpTemp));

			return lpTemp;
		}
#pragma region 이미지 추가 실패
		DEBUG_LOG("Key : " << key <<  "path : " << path);
		DEBUG_LOG("경로를 확인해주세요");
		return nullptr;
#pragma endregion
	}

	return find->second;
}

vector<texture*>* cImageManager::AddListImage(const string & key, const TCHAR * path, int count)
{
	auto find = m_listImage.find(key);

	if (find == m_listImage.end())
	{
		vector<texture*> * tempvector = new vector<texture*>;

		for (int i = 1; i <= count; i++)
		{
			LPDIRECT3DTEXTURE9 lpTemp;
			D3DXIMAGE_INFO info;

			TCHAR * tempstr = new TCHAR[wcslen(path) + 2];

			wsprintfW(tempstr, path, i);
	
			if (D3DXCreateTextureFromFileEx(g_Device, tempstr, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0, 
				D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &lpTemp) == S_OK)
			{
				texture * text = new texture(lpTemp, info);
				tempvector->push_back(text);

				SAFE_DELETE_ARRAY(tempstr);
			}
			else
			{
				DEBUG_LOG("key : " << key);
				DEBUG_LOGW(L"경로: " << tempstr);
				DEBUG_LOG("다시 확인해주세요");
				SAFE_DELETE_ARRAY(tempstr);
				return nullptr;
			}
		}

		m_listImage.insert(make_pair(key, tempvector));
		return tempvector;
	}

	return find->second;
}

texture * cImageManager::FindSingleImage(const string & key)
{
	auto find = m_singleImage.find(key);

	if (find == m_singleImage.end())
	{
		DEBUG_LOG("Error! FAILED FindSingleImage ImageKey : " << key);
		DEBUG_LOG("comment : Image를 찾을 수 없습니다.");
		return nullptr;
	}
	
	return find->second;
}

vector<texture*>* cImageManager::FindListImage(const string & key)
{
	auto find = m_listImage.find(key);

	if (find == m_listImage.end())
	{
		DEBUG_LOG("Error! FAILED FindListImage ImageKey : " << key);
		DEBUG_LOG("comment : ImageList를 찾을 수 없습니다.");
		return nullptr;
	}
	return find->second;
}

void cImageManager::DeleteListImage(const string & key)
{
	auto find = m_listImage.find(key);

	if (find == m_listImage.end())
	{
		DEBUG_LOG("FAILED! DeleteListImage ListKey:	" << key);
		DEBUG_LOG("comment : 이미지를 찾지 못했습니다!");
	} 
	else
	{
		for (auto Iter = (*find->second).begin(); Iter != (*find->second).end();)
		{
			(*Iter)->lpTexture->Release();
			SAFE_DELETE((*Iter));
			Iter = (*find->second).erase(Iter);
		}
		(*find->second).clear();
		SAFE_DELETE(find->second);
		m_listImage.erase(find);


	}
}

void cImageManager::DeleteSingleImage(const string & key)
{

	auto find = m_singleImage.find(key);

	if (find != m_singleImage.end())
	{

		(*find).second->lpTexture->Release();
		(*find).second->lpTexture = nullptr;

		SAFE_DELETE((*find).second);
	}
	else
	{
		DEBUG_LOG("Error! FAILED DeleteSingleImage IMAGEKEY	: " << key);
		DEBUG_LOG("comment : 이미지를 찾을 수 없습니다.");
	}
	m_singleImage.erase(find);
}

void cImageManager::Render(texture * _lpTexture, float x, float y, float size, float rot, D3DCOLOR color)
{
	if (_lpTexture)
	{
		D3DXMATRIXA16 mat;
		
		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(_lpTexture->lpTexture, nullptr, nullptr, nullptr, color);
	}
}

void cImageManager::Render(texture * _lpTexture, float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color)
{
	if (_lpTexture)
	{
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(_lpTexture->lpTexture, &srcRect, nullptr, nullptr, color);
	}
}

void cImageManager::Render(texture * _lpTexture, float x, float y, float size, float rot, D3DXVECTOR3 center, D3DCOLOR color)
{
	if (_lpTexture)
	{
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(_lpTexture->lpTexture, nullptr, &center, nullptr, color);
	}
}

void cImageManager::Render(texture * _lpTexture, float x, float y, float size, float rot, D3DXVECTOR3 center, RECT srcRect, D3DCOLOR color)
{
	if (_lpTexture)
	{
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(_lpTexture->lpTexture, &srcRect, &center, nullptr, color);
	}
}

void cImageManager::CenterRender(texture * _lpTexture, float x, float y, float size, float rot, D3DCOLOR color)
{
	this->Render(_lpTexture, x - _lpTexture->info.Width / 2, y - _lpTexture->info.Height / 2, size, rot, color);
}

void cImageManager::CenterRender(texture * _lpTexture, float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color)
{
	this->Render(_lpTexture, x - _lpTexture->info.Width / 2, y - _lpTexture->info.Height / 2, size, rot, srcRect, color);
}

void texture::Render(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, color);
}

void texture::Render(float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, srcRect, color);
}

void texture::Render(float x, float y, float size, float rot, D3DXVECTOR3 center, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, center, color);
}

void texture::Render(float x, float y, float size, float rot, D3DXVECTOR3 center, RECT srcRect, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, center, srcRect, color);
}

void texture::CenterRender(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->CenterRender(this, x, y, size, rot, color);
}

void texture::CenterRender(float x, float y, float size, float rot, RECT srcRect, D3DCOLOR color)
{
	IMAGEMANAGER->CenterRender(this, x, y, size, rot, srcRect, color);
}
