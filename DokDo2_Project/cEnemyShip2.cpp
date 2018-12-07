#include "DXUT.h"
#include "cEnemyShip2.h"
#include "cEnemyBullet.h"



cEnemyShip2::cEnemyShip2(D3DXVECTOR2 pos, int movePattern)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 50, 200);
	
	cEnemy::Init("Ingame_Enemy_Ship02", objectInfo, nullptr, 200, 200);
	m_hitImage = IMAGEMANAGER->FindSingleImage("Ingame_Enemy_Ship02_Hit");

	m_movePattern = movePattern;

	if (m_movePattern == 0)
	{
		m_direction = D3DXVECTOR2(0, 1);
	}
	else if (m_movePattern == 1)
	{
		m_dirList = new D3DXVECTOR2[2];

		m_dirList[0] = D3DXVECTOR2(0, 1);
		m_dirList[1] = D3DXVECTOR2(0, -1);
		m_direction = m_dirList[0];
 
		m_createTime = timeGetTime() + 10000;
	}

	m_turret.push_back(new turret02(m_Info->m_pos));

	m_giveScore = 500;
}

cEnemyShip2::~cEnemyShip2()
{
}

void cEnemyShip2::Update()
{
	Move();
	Fire();

	m_Info->Update();
}

void cEnemyShip2::Fire()
{
	for (auto Iter : m_turret)
	{
		Iter->Attack();
	}
}

void cEnemyShip2::Move()
{

	if (m_movePattern == 1)
	{
		if (m_Info->m_pos.y < CENTERSCREENY - 200 && m_dirList[0] != D3DXVECTOR2(0, 0))
		{
			m_direction = m_dirList[0];
		}
		else
		{
			m_direction = D3DXVECTOR2(0, 0);
			m_dirList[0] = D3DXVECTOR2(0, 0);
		}
	}

	if (m_createTime < timeGetTime())
	{
		m_direction = m_dirList[1];
	}

	m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());

	for (auto Iter : m_turret) {
		Iter->GetInfo()->m_pos = D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y);
	}

}

void cEnemyShip2::Animation()
{
}

turret02::turret02(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos);

	turret::Init("Ingame_Enemy_Ship02_Turret", objectInfo);

	m_Info->m_centerPos = D3DXVECTOR3(m_image->info.Width / 2, m_image->info.Height / 2 - 20, 0.0f);

	m_attackTime = timeGetTime() + 2000;
}

turret02::~turret02()
{
}

void turret02::Attack()
{
	D3DXVECTOR2 bulletDirection;

	if (OBJECTMANAGER->GetPlayer() != nullptr)
	{
		bulletDirection = OBJECTMANAGER->GetPlayer()->GetPos() - m_Info->m_pos;
		D3DXVec2Normalize(&bulletDirection, &bulletDirection);
	

		m_Info->m_rot = (float)acos(D3DXVec2Dot(&D3DXVECTOR2(0, 1), &bulletDirection));

		if (OBJECTMANAGER->GetPlayer()->GetPos().x > m_Info->m_pos.x)
			m_Info->m_rot *= -1;

		if (m_attackTime < timeGetTime())
		{
			if (m_attackCount < 2)
			{ 
				m_attackTime = timeGetTime() + 500;

				cEnemyBullet * bullet = new cEnemyBullet("Ingame_Enemy_Bullet01", D3DXVECTOR2(m_Info->m_pos.x + 15, m_Info->m_pos.y) , bulletDirection, 300);
				OBJECTMANAGER->AddObject(OBJECTTYPE::EBULLET, bullet);

				bullet = new cEnemyBullet("Ingame_Enemy_Bullet01", D3DXVECTOR2(m_Info->m_pos.x - 15, m_Info->m_pos.y), bulletDirection, 300);
				OBJECTMANAGER->AddObject(OBJECTTYPE::EBULLET, bullet);
				m_attackCount++;
			}
			else
			{
				m_attackTime = timeGetTime() + 1500;
				m_attackCount = 0;
			}
			
		}
	}

	


	
	
}
