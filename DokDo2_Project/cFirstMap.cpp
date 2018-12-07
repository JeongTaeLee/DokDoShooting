#include "DXUT.h"
#include "cFirstMap.h"


cFirstMap::cFirstMap()
{
	cMap::Init("Ingame_FirstMap", D3DXVECTOR2(CENTERSCREENX, CENTERSCREENY), 500);
}


cFirstMap::~cFirstMap()
{
}

void cFirstMap::Update()
{
	m_scrool += m_speed * DXUTGetElapsedTime();
    
	m_Info->m_pos.y = (int)m_scrool % m_nowImage->info.Height;
}
