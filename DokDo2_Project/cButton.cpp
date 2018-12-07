#include "DXUT.h"
#include "cButton.h"


cButton::cButton()
{
	m_onButton = false;
	mousePos = { 0, 0 };
}


cButton::~cButton()
{
}

void cButton::Render()
{
	m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y);
}

void cButton::OnButton()
{
	m_aniInfo->nowFrame = 1;

	m_Info->m_collisionX = 300;
	m_Info->m_collisionY = 115;
}

void cButton::OffButton()
{
	m_aniInfo->nowFrame = 0;

	m_Info->m_collisionX = 172;
	m_Info->m_collisionY = 115;
}
