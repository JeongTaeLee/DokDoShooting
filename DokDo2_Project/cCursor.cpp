#include "DXUT.h"
#include "cCursor.h"


cCursor::cCursor()
{
	
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);
	cObjectInfo * objectInfo = new cObjectInfo(D3DXVECTOR2(0, 0), 0, 0, true);

	cUi::Init("Ingame_Cursor", aniInfo, objectInfo);
}


cCursor::~cCursor()
{
}

void cCursor::Update()
{
	GetCursorPos(&m_mousePos);
	ScreenToClient(DXUTGetHWND(), &m_mousePos);

	m_Info->m_pos.x = m_mousePos.x;
	m_Info->m_pos.y = m_mousePos.y;
		
	if (GetAsyncKeyState(VK_LBUTTON)) {
		m_aniInfo->nowFrame = 1;
	}
	else
		m_aniInfo->nowFrame = 0;
	
	
		

	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
}
