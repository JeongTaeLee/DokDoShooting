#include "DXUT.h"
#include "cFirstCloud.h"


cFirstCloud::cFirstCloud()
{
	cMap::Init("Ingame_FirstCloud", D3DXVECTOR2(CENTERSCREENX, CENTERSCREENY), 1000);
}


cFirstCloud::~cFirstCloud()
{
}

void cFirstCloud::Update()
{
	m_scrool = m_speed * DXUTGetElapsedTime();

	m_Info->m_pos.y += (int)m_scrool % m_nowImage->info.Height;
}
