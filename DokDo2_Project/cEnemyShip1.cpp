#include "DXUT.h"
#include "cEnemyShip1.h"
#include "cBulletLib.h"




cEnemyShip1::cEnemyShip1(D3DXVECTOR2 pos, int movePattern)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 55, 155);

	cEnemy::Init("Ingame_Enemy_Ship01", objectInfo, nullptr, 200, 300);
	m_hitImage = IMAGEMANAGER->FindSingleImage("Ingame_Enemy_Ship01_Hit");
	m_movePattern = movePattern;
	m_giveScore = 200;

	if (m_movePattern == 0)
	{
		m_dirList = new D3DXVECTOR2[2];

		m_dirList[0] = D3DXVECTOR2(0, 1);
		m_dirList[1] = D3DXVECTOR2(0, -1);

		m_direction = m_dirList[0];

		m_createTime = timeGetTime() + 10000;
		
		m_turret.push_back(new turret01(D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y)));
	}
	else if (m_movePattern == 1)
	{
		D3DXVECTOR2 tempDirection = D3DXVECTOR2(0, 1);
		m_direction = D3DXVECTOR2(CENTERSCREENX, m_Info->m_pos.y) - m_Info->m_pos;

		D3DXVec2Normalize(&tempDirection, &tempDirection);
		D3DXVec2Normalize(&m_direction, &m_direction);

		m_Info->m_rot = (float)acos(D3DXVec2Dot(&tempDirection, &m_direction));

		if (m_Info->m_pos.x < GAMESIZELEFT)
		{
			m_turret.push_back(new turret01(D3DXVECTOR2(m_Info->m_pos.x + 50, m_Info->m_pos.y)));
			m_Info->m_rot *= -1;
		}
		else
		{
			m_turret.push_back(new turret01(D3DXVECTOR2(m_Info->m_pos.x - 50, m_Info->m_pos.y)));
		}
		m_createTime = timeGetTime() + 10000;
	}



}



cEnemyShip1::~cEnemyShip1()
{
}

void cEnemyShip1::Update()
{
	//m_turret[0]->m_Info->m_pos = D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y - 100);
	Move();
	Fire();
	Animation();

	m_Info->m_color = D3DCOLOR_XRGB(255, 255, 255);
	m_Info->Update();
	//DEBUG_LOG("in");
}

void cEnemyShip1::Move()
{
	if (m_movePattern == 0)
	{
		if (m_createTime < timeGetTime())
		{
			m_direction = m_dirList[1];
		}
		else if (m_Info->m_pos.y > CENTERSCREENY - 150 && m_dirList[0] != D3DXVECTOR2(0, 0))
		{
			m_dirList[0] = D3DXVECTOR2(0, 0);
			m_direction = m_dirList[0];
		
		}

		m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());

		for (auto Iter : m_turret)
			Iter->GetInfo()->m_pos = D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y + 50);

	}

	if (m_movePattern == 1)
	{
		if (m_Info->m_pos.x < CENTERSCREENX)
		{
			if (m_Info->m_pos.x < GAMESIZELEFT + 155)
			{
				m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
			}

			if(m_createTime < timeGetTime())
				m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
		}
		else
		{
			if (m_Info->m_pos.x > CENTERSCREENY)
			{
				if (m_Info->m_pos.x > GAMESIZERIGHT - 155)
				{



					m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
				}
			
				if (m_createTime < timeGetTime())
					m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
			}

		}
	
		for (auto Iter : m_turret)
		{
			if (m_Info->m_pos.x < GAMESIZELEFT + 155 + 50)
				Iter->GetInfo()->m_pos = D3DXVECTOR2(m_Info->m_pos.x + 50, m_Info->m_pos.y);
			else
				Iter->GetInfo()->m_pos = D3DXVECTOR2(m_Info->m_pos.x - 50, m_Info->m_pos.y);
		}

		m_Info->Update();
	}
	}
	

void cEnemyShip1::Animation()
{
}

void cEnemyShip1::Fire()
{
	for (auto Iter : m_turret)
		Iter->Attack();
}



turret01::turret01(D3DXVECTOR2 pos)
{
	cObjectInfo * Info = new cObjectInfo(pos);

	turret::Init("Ingame_Enemy_Ship01_Turret", Info);

	m_Info->m_centerPos = D3DXVECTOR3(m_image->info.Width / 2, m_image->info.Height / 2, 0.0f);

	m_attackCount = timeGetTime() + 2000;
}

turret01::~turret01()
{
}

// turret
void turret01::Attack()
{
		if (OBJECTMANAGER->GetPlayer() != nullptr)
		{
			D3DXVECTOR2 tempDirection = D3DXVECTOR2(1, 0);
			D3DXVECTOR2 m_direction = OBJECTMANAGER->GetPlayer()->GetPos() - m_Info->m_pos;


			D3DXVec2Normalize(&m_direction, &m_direction);
			D3DXVec2Normalize(&tempDirection, &tempDirection);

			m_Info->m_rot = (float)acos(D3DXVec2Dot(&tempDirection, &m_direction));


			if (m_attackTime < timeGetTime())
			{

				if (m_attackCount < 3)
				{
					m_attackTime = timeGetTime() + 200;

					int randomSpeed = randomRange(200, 350);

					m_attackCount % 2 ?  NwayBullet("Ingame_Enemy_Bullet01", m_Info->m_pos, m_direction, 2, 15, randomSpeed): NwayBullet("Ingame_Enemy_Bullet01", m_Info->m_pos, m_direction, 3, 20, randomSpeed);

					m_attackCount++;
				}
				else
				{
					m_attackTime = timeGetTime() + 2500;
					m_attackCount = 0;
				}
			}
			//DEBUG_LOG(m_Info->m_rot);
		}

}
