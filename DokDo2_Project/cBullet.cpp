#include "DXUT.h"
#include "cBullet.h"


cBullet::cBullet()
{
	m_tag = "Bullet";
	m_direction = D3DXVECTOR2(0, 0);
}


cBullet::~cBullet()
{
	
}

void cBullet::Init(const string & key, cObjectInfo * objectInfo, cAnimationInfo * aniInfo, float speed, float damage)
{
	cGameObject::Init(key, objectInfo, aniInfo);

	m_speed = speed;
	m_damage = damage;
}

void cBullet::CollisionCheck(cGameObject * object)
{
	m_deleteObject = true;
	//DEBUG_LOG("in");
}

bool cBullet::IsOutMap()
{
	return (m_Info->m_pos.x < GAMESIZELEFT - (m_Info->m_collisionX * 3) ||
		m_Info->m_pos.x > GAMESIZERIGHT + (m_Info->m_collisionX * 3) ||
		m_Info->m_pos.y < GAMESIZETOP - (m_Info->m_collisionY * 3) ||
		m_Info->m_pos.y > GAMESIZEBOTTOM + (m_Info->m_collisionY * 3));
}
