#include "DXUT.h"
#include "cStoryButton.h"
#include "MyLib.h"
#include "cScreen.h"


cStoryButton::cStoryButton()
{
}


cStoryButton::~cStoryButton()
{
}

void cStoryButton::Init(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 175, 115, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);

	cGameObject::Init("Intro_StoryButton", objectInfo, aniInfo);
}

void cStoryButton::Update()
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
				Screen = new cScreen;
				OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Screen);
				Screen->Init("Intro_StoryScreen", D3DXVECTOR2(WINSIZEX / 2, WINSIZEY / 2));
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
		if (Screen->GetDelete())
		{
			m_onButton = false;
		}
	}


	m_nowImage = (*m_images)[m_aniInfo->nowFrame];

	m_Info->Update();
}
