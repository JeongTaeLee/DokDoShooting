#include "DXUT.h"
#include "cObjectInfo.h"



cObjectInfo::cObjectInfo(D3DXVECTOR2 pos, float CollisionX, float CollisionY, bool initC, D3DCOLOR color)
	:m_pos(pos), m_collisionX(CollisionX), m_collisionY(CollisionY), m_rot(0.0f), initCenter(initC), m_color(color)
{
	if (initCenter)
		SetRect(&m_collision, m_pos.x - m_collisionX / 2, m_pos.y - m_collisionY / 2, m_pos.x + m_collisionX / 2, m_pos.y + m_collisionY / 2);
	else
		SetRect(&m_collision, m_pos.x, m_pos.y, m_pos.x + m_collisionX, m_pos.y + m_collisionY);
}

cObjectInfo::~cObjectInfo()
{
}

void cObjectInfo::Update()
{
	if (initCenter)
		SetRect(&m_collision, m_pos.x - m_collisionX / 2, m_pos.y - m_collisionY / 2, m_pos.x + m_collisionX / 2, m_pos.y + m_collisionY / 2);
	else
		SetRect(&m_collision, m_pos.x, m_pos.y, m_pos.x + m_collisionX, m_pos.y + m_collisionY);
}
