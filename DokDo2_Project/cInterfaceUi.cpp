#include "DXUT.h"
#include "cInterfaceUi.h"
#include "cPlayer.h"

cInterfaceUi::cInterfaceUi()
{
	cObjectInfo * objectInfo = new cObjectInfo(D3DXVECTOR2(0, 0), 0, 0, false);

	cUi::Init("Ingame_InterfaceUi", nullptr, objectInfo);

	m_scoreText = new TCHAR[10];
	wsprintf(m_scoreText, TEXT("SCORE"));

	m_scoreNum = new TCHAR[10];
	wsprintf(m_scoreNum, TEXT("%06d"), 0);

	m_hpText = new TCHAR[10];
	wsprintf(m_hpText, TEXT("X %d"), 0);

	m_powerText = new TCHAR[10];
	wsprintf(m_powerText, TEXT("X %d"), 0);

	m_coinText = new TCHAR[10];
	wsprintf(m_coinText, TEXT("X %d"), 0);
}


cInterfaceUi::~cInterfaceUi()
{
	Release();
}

void cInterfaceUi::Update()
{
	cPlayer * temp = nullptr;
	if(OBJECTMANAGER->GetPlayer() != nullptr)
		temp = dynamic_cast<cPlayer*>(OBJECTMANAGER->GetPlayer());
	
	if (temp != nullptr)
	{
		wsprintf(m_scoreNum,	L"%06d", GAMEMANAGER->GetScore());
		wsprintf(m_hpText,		L"X %d", temp->GetHp());
		wsprintf(m_powerText,	L"X%03d", temp->GetPowerUp());
		wsprintf(m_coinText,	L"X%03d", temp->GetCoin());
	}
}

void cInterfaceUi::Render()
{
	if (m_Info->initCenter)
		m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, 0.0f, m_Info->m_centerPos, m_Info->m_color);
	else
		m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, 0.0f, m_Info->m_color);


	TEXTMANAGER->drawText(m_scoreText, D3DXVECTOR2(100, 55), D3DCOLOR_XRGB(255, 255, 255), 0);
	TEXTMANAGER->drawText(m_scoreNum, D3DXVECTOR2(85, 90), D3DCOLOR_XRGB(255, 255, 255), 0);
	TEXTMANAGER->drawText(m_hpText,		D3DXVECTOR2(110, 225), D3DCOLOR_XRGB(255, 255, 255), 1);
	TEXTMANAGER->drawText(m_coinText, D3DXVECTOR2(145, 575), D3DCOLOR_XRGB(255, 255, 255), 0);
	TEXTMANAGER->drawText(m_powerText, D3DXVECTOR2(145, 610), D3DCOLOR_XRGB(255, 255, 255), 0);

}


void cInterfaceUi::Release()
{
	delete[] m_scoreText;
	m_scoreText = nullptr;

	SAFE_DELETE_ARRAY(m_scoreNum);
	SAFE_DELETE_ARRAY(m_hpText);
	SAFE_DELETE_ARRAY(m_coinText);
	SAFE_DELETE_ARRAY(m_powerText);
}
