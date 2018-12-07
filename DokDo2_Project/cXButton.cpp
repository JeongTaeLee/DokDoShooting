#include "DXUT.h"
#include "cXButton.h"
#include "MyLib.h"


cXButton::cXButton()
{
}


cXButton::~cXButton()
{
}

void cXButton::Init(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 60, 60, false);
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);

	cGameObject::Init("Button_XButton", objectInfo, aniInfo);
}

void cXButton::Update()
{
	GetCursorPos(&mousePos);
	ScreenToClient(DXUTGetHWND(),&mousePos);

	if (IsPointCollision(m_Info->m_collision, mousePos))
	{
		if (KEY_DOWN(VK_LBUTTON))
		{
			OnButton();
			m_onButton = true;
			m_deleteObject = true;
		}
	}
	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
}

void cXButton::OnButton()
{
	m_aniInfo->nowFrame = 1;
}

void cXButton::OffButton()
{
	m_aniInfo->nowFrame = 0;

}
