#include "DXUT.h"
#include "cPlayer.h"
#include "cExplosions.h"

cPlayer::cPlayer()
{
	m_hp		= 3;
	m_powerUp	= 0;
	m_coinUp	= 0;
	m_speed		= 500;

	m_attackCount = 0;

	m_attackTime = 0;
	m_reCreateTime = 0;
	m_deadTime = 0;
	m_nowTime = 0;
}


cPlayer::~cPlayer()
{
}

void cPlayer::Init(D3DXVECTOR2 pos)
{
	cObjectInfo *	 objectInfo = new cObjectInfo(pos, 10, 15, true);
	cAnimationInfo * aniInfo	= new cAnimationInfo(6, 3, false, 30);

	cGameObject::Init("Ingame_Player_AirPlane", objectInfo, aniInfo);

	//m_dir = D3DXVECTOR2(0, -1);
}

void cPlayer::Update()
{
	Move();
	Animation();

	m_Info->Update();
}

void cPlayer::Move()
{
	
	m_aniInfo->aniState = IDLE;
	
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_aniInfo->aniState = LEFT;
		if (m_Info->m_pos.x - (m_speed * DXUTGetElapsedTime()) > GAMESIZELEFT + 30)
			m_Info->m_pos.x -= m_speed * DXUTGetElapsedTime();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_aniInfo->aniState = RIGHT;
		if (m_Info->m_pos.x + (m_speed * DXUTGetElapsedTime()) < GAMESIZERIGHT - 30)
			m_Info->m_pos.x += m_speed * DXUTGetElapsedTime();
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (m_Info->m_pos.y - (m_speed * DXUTGetElapsedTime()) > GAMESIZETOP + 40)
			m_Info->m_pos.y -= m_speed * DXUTGetElapsedTime();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_Info->m_pos.y + (m_speed * DXUTGetElapsedTime()) < GAMESIZEBOTTOM - 40)
			m_Info->m_pos.y += (m_speed * DXUTGetElapsedTime());
	}
}

void cPlayer::Fire()
{
}

void cPlayer::Animation()
{
	if (m_aniInfo->nowTime < timeGetTime())
	{
		m_aniInfo->nowTime = timeGetTime() + m_aniInfo->frameTime;
		switch (m_aniInfo->aniState)
		{
		case IDLE:
			if(m_aniInfo->nowFrame != m_aniInfo->idleFrame)
			{
				if (m_aniInfo->nowFrame > m_aniInfo->idleFrame)
					m_aniInfo->nowFrame--;
				else if (m_aniInfo->nowFrame < m_aniInfo->idleFrame)
					m_aniInfo->nowFrame++;
			}
			break;

		case LEFT:
			if (m_aniInfo->nowFrame != 0)
				m_aniInfo->nowFrame--;
			break;
		case RIGHT :
			if (m_aniInfo->nowFrame != m_aniInfo->maxFrame)
				m_aniInfo->nowFrame++;
			break;
		}

		m_nowImage = (*m_images)[m_aniInfo->nowFrame];
	}
}



void cPlayer::CollisionCheck(cGameObject * object)
{
	if (m_hp < 0)
	{
		m_deleteObject = true;
	}
	else if(m_deadTime == 0 && m_reCreateTime == 0)
	{
		m_hp -= 1;
		if(m_aniInfo != nullptr)
			m_aniInfo->aniState = DEAD;

		cExplosions * explosions = new cExplosions(m_Info->m_pos);
		OBJECTMANAGER->AddObject(ENEMY, explosions);

		m_deadTime = timeGetTime() + 1000;
		//m_reCreateTime = timeGetTime() + 3000;
	}
}
