#include "DXUT.h"
#include "cEnemyPlane03.h"
#include "cBulletLib.h"


cEnemyPlane03::cEnemyPlane03(D3DXVECTOR2 pos, int movePattern)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 42, 200);
	cAnimationInfo * aniInfo = new cAnimationInfo(6, 3, false, 50);

	cEnemy::Init("Ingame_Enemy_Plane03", objectInfo, aniInfo, 400, 300);

	m_movePattern = movePattern;

	if (m_movePattern == 0)
	{
		m_dirList = new D3DXVECTOR2[2];
		m_dirList[0] = D3DXVECTOR2(CENTERSCREENX, m_Info->m_pos.y);

		if (m_Info->m_pos.x < GAMESIZELEFT)
		{
			m_aniInfo->aniState = RIGHT;
			m_dirList[1] = D3DXVECTOR2(m_dirList[0].x * -1, m_Info->m_pos.y);
		}
		else
		{
			m_aniInfo->aniState = LEFT;
			m_dirList[1] = D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y);
		}

		m_direction = m_dirList[0] - m_Info->m_pos;
		D3DXVec2Normalize(&m_direction, &m_direction);

		m_createTime = timeGetTime() + 15000;
		m_attackTime = timeGetTime() + 1000;

	}

	m_giveScore = 500;

}

cEnemyPlane03::~cEnemyPlane03()
{
}

void cEnemyPlane03::Update()
{
	Move();
	Fire();
	Animation();

	m_Info->Update();
	m_Info->m_color = D3DCOLOR_XRGB(255, 255, 255);
}

void cEnemyPlane03::Move()
{
	if (m_movePattern == 0)
	{
		if (m_createTime < timeGetTime())
		{
			if (m_speed < 300)
				m_speed += 20;
			else
			{
				if (m_Info->m_pos.x < CENTERSCREENX)
					m_aniInfo->aniState = LEFT;
				else
					m_aniInfo->aniState = RIGHT;
			}

			if (m_dirList[1] != D3DXVECTOR2(-1, -1))
			{
				m_direction = m_dirList[1] - m_Info->m_pos;
				D3DXVec2Normalize(&m_direction, &m_direction);
				m_dirList[1] = D3DXVECTOR2(-1, -1);
			}
		}
		else
		{
			if (m_speed > 1)
				m_speed -= 3;
			else
				m_aniInfo->aniState = IDLE;
		}


		m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
	}
}

void cEnemyPlane03::Fire()
{
	if (m_attackTime < timeGetTime())
	{
		if (m_attackCount < 3)
		{
			m_attackTime = timeGetTime() + 400;

			D3DXVECTOR2 direction01;
			D3DXVECTOR2 direction02;
			D3DXVECTOR2 firePos01 = D3DXVECTOR2(m_Info->m_pos.x - 40, m_Info->m_pos.y + 10);
			D3DXVECTOR2 firePos02 = D3DXVECTOR2(m_Info->m_pos.x + 40, m_Info->m_pos.y + 10);

			if (OBJECTMANAGER->GetPlayer() != nullptr)
			{
				direction01 = OBJECTMANAGER->GetPlayer()->GetPos() - firePos01;
				direction02 = OBJECTMANAGER->GetPlayer()->GetPos() - firePos02;
			
			
				D3DXVec2Normalize(&direction01, &direction01);
				D3DXVec2Normalize(&direction02, &direction02);

				m_attackCount % 2 ? NwayBullet("Ingame_Enemy_Bullet01", firePos01, direction01, 2, 15, 400) : NwayBullet("Ingame_Enemy_Bullet01", firePos01, direction01, 3, 15, 400);
				m_attackCount % 2 ? NwayBullet("Ingame_Enemy_Bullet01", firePos02, direction02, 2, 15, 400) : NwayBullet("Ingame_Enemy_Bullet01", firePos02, direction02, 3, 15, 400);

			}
			m_attackCount++;
		}
		else
		{
			m_attackTime = timeGetTime() + 5000;
			m_attackCount =0;
			DEBUG_LOG("in");
			
		}
	}
}

void cEnemyPlane03::Animation()
{
	if (m_aniInfo->nowTime < timeGetTime())
	{
		m_aniInfo->nowTime = timeGetTime() + m_aniInfo->frameTime;

		switch (m_aniInfo->aniState)
		{
		case AniState::RIGHT:
			if (m_aniInfo->nowFrame != m_aniInfo->maxFrame)
				m_aniInfo->nowFrame++;
			break;
		
		case AniState::LEFT:
			if (m_aniInfo->nowFrame != 0)
				m_aniInfo->nowFrame;
			break;

		case AniState::IDLE:
			if (m_aniInfo->nowFrame != m_aniInfo->idleFrame)
			{
				if (m_aniInfo->nowFrame < m_aniInfo->idleFrame)
					m_aniInfo->nowFrame++;
				else if (m_aniInfo->nowFrame > m_aniInfo->idleFrame)
					m_aniInfo->nowFrame--;
			}
			break;
		}
		
		m_nowImage = (*m_images)[m_aniInfo->nowFrame];
	}
}
