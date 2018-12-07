#include "DXUT.h"
#include "cEnemyPlane.h"


cEnemyPlane::cEnemyPlane()
{
	m_attackCount = 0;
	m_attackPattern = 0;
}


cEnemyPlane::~cEnemyPlane()
{
}

void cEnemyPlane::Render()
{
	m_nowImage->Render(m_Info->m_pos.x + 70, m_Info->m_pos.y + 60, 0.5f, m_Info->m_rot, m_Info->m_centerPos, D3DCOLOR_ARGB(150,0, 0, 0));
	m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot,m_Info->m_centerPos, m_Info->m_color);
}


