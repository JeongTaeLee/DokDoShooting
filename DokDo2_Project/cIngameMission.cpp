#include "DXUT.h"
#include "cIngameMission.h"


cIngameMission::cIngameMission()
{
	cAnimationInfo * aniInfo = new cAnimationInfo(1, 0);
	cObjectInfo * objectInfo = new cObjectInfo(D3DXVECTOR2(0, 0), 0, 0, false);

	cUi::Init("Ingmae_StageMission", aniInfo, objectInfo);
}


cIngameMission::~cIngameMission()
{
}



void cIngameMission::Update()
{
	if (GAMEMANAGER->GetStage() == 1)
		m_aniInfo->nowFrame = 0;
	else if (GAMEMANAGER->GetStage() == 2)
		m_aniInfo->nowFrame = 1;

	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
}
