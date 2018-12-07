#include "DXUT.h"
#include "cDevloperButton.h"
#include "MyLib.h"
#include "cScreen.h"

cDevloperButton::cDevloperButton()
{
}


cDevloperButton::~cDevloperButton()
{
}

void cDevloperButton::Init(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 175, 115, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);

	cGameObject::Init("Intro_DevloperButton", objectInfo, aniInfo);
}

void cDevloperButton::Update()
{
	GetCursorPos(&mousePos);
	ScreenToClient(DXUTGetHWND(), &mousePos);

	if (IsPointCollision(m_Info->m_collision, mousePos))
	{
		OnButton();

		if (!m_onButton)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				Devloper = new cScreen;
				OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Devloper);
				Devloper->Init("Intro_DevloperScreen", D3DXVECTOR2(WINSIZEX / 2, WINSIZEY / 2));
				m_onButton = true;
	
			}
		}
	}
	else
	{
		OffButton();
	}

	if (m_onButton)
	{
		if (Devloper->GetDelete())
		{
			m_onButton = false;
		}
	}

	m_nowImage = (*m_images)[m_aniInfo->nowFrame];

	m_Info->Update();
}
