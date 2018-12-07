#include "DXUT.h"
#include "cGameObject.h"


cGameObject::cGameObject()
{
	m_Info			= nullptr;
	m_aniInfo		= nullptr;
	m_deleteObject	= false;
	m_shadow		= false;
}


cGameObject::~cGameObject()
{
	Release();
	
	SAFE_DELETE(m_Info);
	SAFE_DELETE(m_aniInfo);
}

void cGameObject::Init(const string & key, cObjectInfo * objectInfo, cAnimationInfo * aniInfo)
{
	if (aniInfo == nullptr)
	{
		m_aniInfo = nullptr;
		
		m_images = nullptr; 
		m_nowImage = IMAGEMANAGER->FindSingleImage(key);
		objectInfo->m_centerPos = D3DXVECTOR3(m_nowImage->info.Width / 2, m_nowImage->info.Height / 2, 0.0f);

		m_Info = objectInfo;
	}
	else
	{
		m_aniInfo				= aniInfo;
		
		m_images				=	IMAGEMANAGER->FindListImage(key);
		m_nowImage				=	(*m_images)[m_aniInfo->idleFrame];
		objectInfo->m_centerPos =	D3DXVECTOR3(m_nowImage->info.Width / 2, m_nowImage->info.Height / 2, 0.0f);

		m_Info = objectInfo;
	}
}

void cGameObject::Update()
{
}

void cGameObject::Render()
{
	if (m_Info->initCenter)
	{ 
		if(m_shadow)
			m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 0.5f, m_Info->m_rot, m_Info->m_centerPos, m_Info->m_color);

		m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot, m_Info->m_centerPos, m_Info->m_color);
	}
	else
	{
		if(m_shadow)
			m_nowImage->CenterRender(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot, m_Info->m_color);

		m_nowImage->CenterRender(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot, m_Info->m_color);
	}
}

void cGameObject::Release()
{
}

bool cGameObject::IsOutMap()
{
	return false;
}

void cGameObject::CollisionCheck(cGameObject * object)
{
}
