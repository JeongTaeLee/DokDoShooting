#include "DXUT.h"
#include "cSecondMap.h"


cSecondMap::cSecondMap()
{
	cMap::Init("Ingame_SecondCloud", D3DXVECTOR2(CENTERSCREENX, CENTERSCREENY), 2000);
}


cSecondMap::~cSecondMap()
{
}

void cSecondMap::Update()
{
	m_scrool += m_speed * DXUTGetElapsedTime();


	m_Info->m_pos.y = (int)m_scrool % m_nowImage->info.Height;
}
