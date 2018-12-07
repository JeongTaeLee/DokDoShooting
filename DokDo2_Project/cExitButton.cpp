#include "DXUT.h"
#include "cExitButton.h"
#include "MyLib.h"



cExitButton::cExitButton()
{
}


cExitButton::~cExitButton()
{
}

void cExitButton::Init(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 175, 115, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);

	cGameObject::Init("Intro_ExitButton", objectInfo, aniInfo);
}

void cExitButton::Update()
{
	GetCursorPos(&mousePos);
	ScreenToClient(DXUTGetHWND(), &mousePos);

	if (IsPointCollision(m_Info->m_collision, mousePos))
	{
		OnButton();

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			exit(1);
		}
	}
	else
	{
		OffButton();
	}


	m_nowImage = (*m_images)[m_aniInfo->nowFrame];

	m_Info->Update();
}
