#include "DXUT.h"
#include "cUi.h"


cUi::cUi()
{
}


cUi::~cUi()
{
}

void cUi::Init(const string & key, cAnimationInfo * aniInfo, cObjectInfo * objectInfo)
{
	if (aniInfo) {
		cGameObject::Init(key, objectInfo, aniInfo);
	}
	else {
		cGameObject::Init(key, objectInfo, nullptr);
	}

}

void cUi::Render()
{
	if (m_Info->initCenter)
		m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, 0.0f, m_Info->m_centerPos, m_Info->m_color);
	else
		m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y,1.0f, 0.0f, m_Info->m_color);
}
