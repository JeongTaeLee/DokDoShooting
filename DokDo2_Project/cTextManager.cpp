#include "DXUT.h"
#include "cTextManager.h"


extern LPD3DXSPRITE g_sprite;

void cTextManager::Init()
{
	D3DXFONT_DESC desc =
	{
		50, 0
		, FW_BOLD, 1, FALSE
		, HANGUL_CHARSET
		, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE
		, TEXT("Impact")
	};

	//wcscpy(desc.FaceName, TEXT("Impact"));

	D3DXCreateFont(g_Device, 50, 0, 10, 1, false, DEFAULT_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_lpFont01);// 이렇게 폰트를 불

	D3DXFONT_DESC desc01 = 
	{
		30, 0
		, FW_BOLD, 1, FALSE
		, HANGUL_CHARSET
		, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE
		, TEXT("Impact")
	};

	D3DXCreateFont(g_Device, 70, 0, 10, 1, false, DEFAULT_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_lpFont02);
}

void cTextManager::Release()
{
	SAFE_RELEASE(m_lpFont01);
	SAFE_RELEASE(m_lpFont02);
}

cTextManager::cTextManager()
{
	Init();
}


cTextManager::~cTextManager()
{
	Release();
}

void cTextManager::drawText(TCHAR * string, D3DXVECTOR2 pos, D3DCOLOR color, int Type)
{
	RECT re = { 0 };

	D3DXMATRIX mat;

	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);

	g_sprite->SetTransform(&mat);

	if (Type == 0)
		m_lpFont01->DrawTextW(g_sprite, string, lstrlen(string), &re, DT_NOCLIP, color);
	else
		m_lpFont02->DrawTextW(g_sprite, string, lstrlen(string), &re, DT_NOCLIP, color);

	//DEBUG_LOG("string:" << lstrlen(string));
}
