#include "DXUT.h"
#include "cStartButton.h"
#include "MyLib.h"


cStartButton::cStartButton()
{
}


cStartButton::~cStartButton()
{
}

void cStartButton::Init(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 0, 0, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(2, 0);

	cGameObject::Init("Intro_StartButton", objectInfo, aniInfo);

	r = false;
}

void cStartButton::Update()
{
	GetCursorPos(&mousePos);
	ScreenToClient(DXUTGetHWND(), &mousePos);

	if (m_Info->m_pos.y < 500)
	{
		m_Info->m_pos.y += 350 * DXUTGetElapsedTime();

		if (GetAsyncKeyState('S') & 0x8001)
		{
			m_Info->m_pos.y = 500;
		}
	}
	else if (r == false)
	{
		m_aniInfo->nowFrame = 1;
		r = true;
		//DEBUG_LOG("in");

		SetRect(&m_Info->m_collision, m_Info->m_pos.x, m_Info->m_pos.y + 150, m_Info->m_pos.x + 270, (m_Info->m_pos.y + 150) + 115);
	}
	else
	{
		if (IsPointCollision(m_Info->m_collision, mousePos))
		{
			m_aniInfo->nowFrame = 2;

			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				//OBJECTMANAGER->Reset();
				SCENEMANAGER->ChangeScene("Stage01");
			}
		}
		else
		{
			m_aniInfo->nowFrame = 1;
		}
	}


	m_nowImage = (*m_images)[m_aniInfo->nowFrame];

}
