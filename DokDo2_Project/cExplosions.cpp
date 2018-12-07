#include "DXUT.h"
#include "cExplosions.h"


cExplosions::cExplosions(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos);
	cAnimationInfo * aniInfo = new cAnimationInfo(26, 0, false, 25);
	
	cGameObject::Init("Ingame_Explosions", objectInfo, aniInfo);
}


cExplosions::~cExplosions()
{
}

void cExplosions::Update()
{
	if (m_aniInfo->endFrame)
		m_deleteObject = true;

	if(m_aniInfo->nowTime < timeGetTime())
	{ 
		m_aniInfo->nowTime = timeGetTime() + m_aniInfo->frameTime;
		m_aniInfo->UpdateFrame();
	}

	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
}
