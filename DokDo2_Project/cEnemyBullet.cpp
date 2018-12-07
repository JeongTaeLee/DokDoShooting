#include "DXUT.h"
#include "cEnemyBullet.h"


cEnemyBullet::cEnemyBullet(const string & key, D3DXVECTOR2 pos,D3DXVECTOR2 direction, float m_bulletSpeed)
{
	cObjectInfo * objectInfo = nullptr;
	m_direction  = direction;

	if (key == "Ingame_Enemy_Bullet01")
	{
		objectInfo = new cObjectInfo(pos, 13, 13);
	
		cBullet::Init(key, objectInfo, nullptr, m_bulletSpeed, 1);
	}
	else if (key == "Ingame_Enemy_Bullet02")
	{
		objectInfo = new cObjectInfo(pos, 18, 18);

		cBullet::Init(key, objectInfo, nullptr, m_bulletSpeed, 1);
	}
	else if (key == "Ingame_Enemy_Bullet03")
	{
		objectInfo = new cObjectInfo(pos, 23, 23);
		
		cBullet::Init(key, objectInfo, nullptr, m_bulletSpeed, 1);
	}

}


cEnemyBullet::~cEnemyBullet()
{
}

void cEnemyBullet::Update()
{
	m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());

	m_Info->m_rot += D3DXToRadian(20);

	m_Info->Update();
}
