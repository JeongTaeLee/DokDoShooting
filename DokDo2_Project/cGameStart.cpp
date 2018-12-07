#include "DXUT.h"
#include "cGameStart.h"


cGameStart::cGameStart()
{
	cObjectInfo * objectInfo = new cObjectInfo(D3DXVECTOR2(GAMESIZELEFT, 0), 0, 0, false);
	objectInfo->m_color = D3DCOLOR_ARGB(0, 0, 0, 0);

	cUi::Init("Ingame_GameStart", nullptr, objectInfo);

	m_nowTime = 0;
	
	m_timeStart = false;
	m_Alpha = 0;
}


cGameStart::~cGameStart()
{
}

void cGameStart::Update()
{
	if (m_timeStart == false){
		m_Alpha += 10;

		m_Info->m_color = D3DCOLOR_ARGB(m_Alpha, 255, 255, 255);
	
		if (m_Alpha > 245)
		{
			m_timeStart = true;
			m_nowTime = timeGetTime() + 1500;
		}
	}
	else if (m_nowTime < timeGetTime())
	{
		m_Alpha -= 10;

		m_Info->m_color = D3DCOLOR_ARGB(m_Alpha, 255, 255, 255);

		if (m_Alpha < 0)
			m_deleteObject = true;
	}

//	DEBUG_LOG("in");
}
