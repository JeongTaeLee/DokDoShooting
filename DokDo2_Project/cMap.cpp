#include "DXUT.h"
#include "cMap.h"


cMap::cMap()
{
}


cMap::~cMap()
{
}

void cMap::Init(const string & key, D3DXVECTOR2 pos, const float speed)
{
	m_scrool	= 0;
	m_speed		= speed;
	cObjectInfo * objectInfo = new cObjectInfo(pos, 0, 0, true);

	cGameObject::Init(key, objectInfo, nullptr);
}

void cMap::Render()
{
	m_nowImage->CenterRender(m_Info->m_pos.x, m_Info->m_pos.y - m_nowImage->info.Height, 1.0f, 0.0f, m_Info->m_color);
	m_nowImage->CenterRender(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, 0.0f, m_Info->m_color);
}
