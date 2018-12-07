#pragma once
#include "singleton.h"
class cTextManager
	:public singleton<cTextManager>
{
private:
	LPD3DXFONT m_lpFont01;
	LPD3DXFONT m_lpFont02;

	void Init();
	void Release();

public:
	cTextManager();
	~cTextManager();


	void drawText(TCHAR * string, D3DXVECTOR2 pos, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255), int Type = 0);
};

#define TEXTMANAGER cTextManager::GetInstance()