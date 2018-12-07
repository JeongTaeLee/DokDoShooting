#include "DXUT.h"
#include "cManualButton.h"
#include "MyLib.h"
#include "cScreen.h"


cManualButton::cManualButton()
{
}


cManualButton::~cManualButton()
{
}

void cManualButton::Init(D3DXVECTOR2 pos)
{
	// 172 115 // 300 115
	cObjectInfo * objectInfo = new cObjectInfo(pos, 175, 115, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);

	cGameObject::Init("Intro_ManualButton", objectInfo, aniInfo);
}

void cManualButton::Update()
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
				Manaul = new cScreen;
				OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manaul);
				Manaul->Init("Intro_ManualScreen", D3DXVECTOR2(WINSIZEX / 2, WINSIZEY / 2));
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
		if (Manaul->GetDelete())
		{
			m_onButton = false;
		}
	}

	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
	
	m_Info->Update();
}
