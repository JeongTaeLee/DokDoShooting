#include "DXUT.h"
#include "cEnemyPlane01.h"
#include "cEnemyBullet.h"


cEnemyPlane01::cEnemyPlane01(D3DXVECTOR2 pos, int movePattern)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 17, 60);
	cAnimationInfo * aniInfo = new cAnimationInfo(19, 0, true, 40);

	cEnemy::Init("Ingame_Enemy_Plane01", objectInfo, aniInfo, 10, 700);

	m_movePattern = movePattern;

	if (m_movePattern == 0) {
		m_direction = D3DXVECTOR2(0, 1);
	}
	else if (m_movePattern == 1){
		m_direction = D3DXVECTOR2(CENTERSCREENX, m_Info->m_pos.y - 200)- m_Info->m_pos;
		D3DXVec2Normalize(&m_direction, &m_direction);
	}
	m_attackTime = timeGetTime() + 300;

	m_Info->m_rot = D3DXToRadian(180);

	m_giveScore = 100;
}



cEnemyPlane01::~cEnemyPlane01()
{
}

void cEnemyPlane01::Update()

{
	Move();
	Fire();
	Animation();
}

void cEnemyPlane01::Move()
{
	if (m_movePattern == 0)
	{
		if (m_speed > 200)
			m_speed -= 20;

		m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
	}
	else if (m_movePattern == 1)
	{
		if (m_speed > 200)
			m_speed -= 30;

		m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
	}


	m_Info->m_color = D3DCOLOR_XRGB(255, 255, 255);
	m_Info->Update();
}

void cEnemyPlane01::Fire()
{
	if (m_attackTime < timeGetTime())
	{
		if (m_attackCount < 1)
		{
			m_attackTime = timeGetTime() + 300;

			if (OBJECTMANAGER->GetPlayer() != nullptr)
			{
				D3DXVECTOR2 firePos = D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y + 20);
				D3DXVECTOR2 direction = OBJECTMANAGER->GetPlayer()->GetPos() - firePos;
				D3DXVec2Normalize(&direction, &direction);

				cEnemyBullet * bullet = new cEnemyBullet("Ingame_Enemy_Bullet01", firePos, direction, 300);
				OBJECTMANAGER->AddObject(OBJECTTYPE::EBULLET, bullet);
				m_attackCount++;
			}
		}
		else
		{
			m_attackTime = timeGetTime() + 2000;
			m_attackCount = 0;
		}

	
	}
}

void cEnemyPlane01::Animation()
{

	if (m_aniInfo->nowTime < timeGetTime())
	{
		m_aniInfo->nowTime = m_aniInfo->frameTime + timeGetTime();

		m_aniInfo->UpdateFrame();

		m_nowImage = (*m_images)[m_aniInfo->nowFrame];
	}
}
