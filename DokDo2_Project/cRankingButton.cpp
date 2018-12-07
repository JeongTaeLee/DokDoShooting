#include "DXUT.h"
#include "cRankingButton.h"
#include "MyLib.h"

cRankingButton::cRankingButton()
{
}


cRankingButton::~cRankingButton()
{
}

void cRankingButton::Init(D3DXVECTOR2 pos)
{
	// 172 115 // 300 115
	cObjectInfo * objectInfo = new cObjectInfo(pos, 175, 115, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);

	cGameObject::Init("Intro_RankingButton", objectInfo, aniInfo);
}

void cRankingButton::Update()
{
	GetCursorPos(&mousePos);
	ScreenToClient(DXUTGetHWND(), &mousePos);

	if (IsPointCollision(m_Info->m_collision, mousePos))
	{
		OnButton();

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{

		}
	}
	else
	{
		OffButton();
	}


	m_nowImage = (*m_images)[m_aniInfo->nowFrame];

	m_Info->Update();
}
