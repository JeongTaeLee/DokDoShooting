#include "DXUT.h"
#include "cStage01Middle.h"
#include "cSplitBullet.h"
#include "cBulletLib.h"

cStage01Middle::cStage01Middle(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 360, 115);
	
	cEnemy::Init("Ingame_Enemy_MiddleBoss", objectInfo, nullptr, 1000, 200);

	m_direction = D3DXVECTOR2(0, 1);

	m_attackTime = timeGetTime() + 3000;
	m_createTime = timeGetTime() + 20000;

	m_giveScore = 1000;
}

cStage01Middle::~cStage01Middle()
{
}

void cStage01Middle::Update()
{
	Move();
	Fire();

	m_Info->Update();
	m_Info->m_color = D3DCOLOR_XRGB(255, 255, 255);
}

void cStage01Middle::Move()
{
	if (m_Info->m_pos.y < CENTERSCREENY - 200)
		m_direction = D3DXVECTOR2(0, 1);
	else
	{
		m_direction = D3DXVECTOR2(0, 0);

		if (m_createTime > timeGetTime())
		{
			if (OBJECTMANAGER->GetPlayer() != nullptr)
			{
				if (OBJECTMANAGER->GetPlayer()->GetPos().x < m_Info->m_pos.x)
					m_direction = D3DXVECTOR2(-1, 0);
				else if (OBJECTMANAGER->GetPlayer()->GetPos().x > m_Info->m_pos.x)
					m_direction = D3DXVECTOR2(1, 0);

				m_speed = 50;
			}
		}
	}

	if (m_createTime < timeGetTime())
		m_direction = D3DXVECTOR2(0, -1);

	m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
}

void cStage01Middle::Fire()
{
	if (m_attackPattern == 0)
	{
		m_attackPattern = randomRange(1, 2);
	}

	if (m_attackTime < timeGetTime())
	{
		if (m_attackPattern == 1)
		{
			if (m_attackCount < 2)
			{
				m_attackTime = timeGetTime() + 400;

				D3DXVECTOR2 firePos01 = D3DXVECTOR2(m_Info->m_pos.x + 100, m_Info->m_pos.y);
				D3DXVECTOR2 firePos02 = D3DXVECTOR2(m_Info->m_pos.x - 100, m_Info->m_pos.y);

				cSplitBullet * bullet = new cSplitBullet(firePos01, D3DXVECTOR2(0, 1), 6, 30, 500);
				OBJECTMANAGER->AddObject(OBJECTTYPE::EBULLET, bullet);

				bullet = new cSplitBullet(firePos02, D3DXVECTOR2(0, 1), 6, 30, 1500);
				OBJECTMANAGER->AddObject(OBJECTTYPE::EBULLET, bullet);
				m_attackCount++;
			}
			else
			{
				m_attackTime = timeGetTime() + 5000;
				m_attackCount = 0;
				m_attackPattern = 0;
			}
		}
		else if (m_attackPattern == 2)
		{
			if (m_attackCount < 3)
			{
				m_attackTime = timeGetTime() + 300;

				NwayBullet("Ingame_Enemy_Bullet02", m_Info->m_pos, D3DXVECTOR2(0, 1), 7, 10, 300);
				
				m_attackCount++;
			}
			else
			{
				m_attackCount = 0;
				m_attackTime = timeGetTime() + 5000;
				m_attackPattern = 0;
			}
		}
	}
}