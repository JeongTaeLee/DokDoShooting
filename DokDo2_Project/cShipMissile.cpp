#include "DXUT.h"
#include "cShipMissile.h"



cShipMissile::cShipMissile(D3DXVECTOR2 pos, D3DXVECTOR2 direction, int LV)
{
	m_tag = "PlayerBullet";

	cObjectInfo * objectInfo = new cObjectInfo(pos, 15, 55);
	cAnimationInfo * aniInfo = new cAnimationInfo(3, 0);

	cBullet::Init("Ingame_Player_Missile", objectInfo, aniInfo, 500, 1.0f);

	D3DXVECTOR2 tempDirection = D3DXVECTOR2(0, -1);
	m_direction = direction - m_Info->m_pos;

	D3DXVec2Normalize(&tempDirection, &tempDirection);
	D3DXVec2Normalize(&m_direction, &m_direction);

	m_Info->m_rot = (float)acos(D3DXVec2Dot(&tempDirection, &m_direction));

	if (direction.x < m_Info->m_pos.x)
		m_Info->m_rot *= -1;

	m_speed = 50;

	if (LV == PLV1)
	{
		m_aniInfo->nowFrame = 0;
		m_Info->m_collisionX = 10;
		m_Info->m_collisionY = 35;

		m_damage = 10;
	}
	else if (LV == PLV2)
	{
		m_aniInfo->nowFrame = 1;

		m_Info->m_collisionX = 15;
		m_Info->m_collisionY = 55;
		m_damage = 20;
	}
	else if (LV == PLV3)
	{
		m_aniInfo->nowFrame = 2;

		m_Info->m_collisionX = 70;
		m_Info->m_collisionY = 57;
		m_damage = 30;
	}
	else if (LV == PLV4)
	{
		m_aniInfo->nowFrame = 3;

		m_Info->m_collisionX = 60;
		m_Info->m_collisionY = 55;
		m_damage = 40;
	}
	
	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
	m_Info->m_centerPos = D3DXVECTOR3(m_nowImage->info.Width / 2, m_nowImage->info.Height / 2 + 20, 0.0f);
	
}

cShipMissile::~cShipMissile()
{
}

void cShipMissile::Update()
{
	m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());

	m_speed += 50;

	m_Info->Update();
}
