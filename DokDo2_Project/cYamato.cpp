#include "DXUT.h"
#include "cYamato.h"


cYamato::cYamato(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 0, 0);

	cEnemy::Init("Ingame_Enemy_Yamato", objectInfo, nullptr, 10000, 200);

	m_direction = D3DXVECTOR2(-1, 0);

	m_turret.push_back(new SmallTurret(D3DXVECTOR2(m_Info->m_pos.x + 300, m_Info->m_pos.y)));
	m_turret.push_back(new SmallTurret(D3DXVECTOR2(m_Info->m_pos.x - 320, m_Info->m_pos.y)));
	m_turret.push_back(new BigTurret(D3DXVECTOR2(m_Info->m_pos.x - 200, m_Info->m_pos.y)));
	OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, m_turret[0]);
	OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, m_turret[1]);
	OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, m_turret[2]);
	m_giveScore = 2000;
}


cYamato::~cYamato()
{
}

void cYamato::Update()
{
	Move();
	Fire();


	m_turret[0]->GetPos() = D3DXVECTOR2(m_Info->m_pos.x + 300, m_Info->m_pos.y);
	m_turret[1]->GetPos() = D3DXVECTOR2(m_Info->m_pos.x - 320, m_Info->m_pos.y);
	m_turret[2]->GetPos() = D3DXVECTOR2(m_Info->m_pos.x - 200, m_Info->m_pos.y);
}

void cYamato::Move()
{
	if (m_Info->m_pos.x > CENTERSCREENX)
	{
		m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
	}
}

void cYamato::Fire()
{
	for (auto Iter : m_turret)
		Iter->Attack();
}

SmallTurret::SmallTurret(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 50, 50);
	
	turret::Init("Ingame_Enemy_Yamato_SmallTurret", objectInfo);

	m_Info->m_centerPos = D3DXVECTOR3(m_image->info.Width / 2, m_image->info.Height / 2 - 20, 0.0f);

	m_attackTime = timeGetTime() + 2000;
}

void SmallTurret::Attack()
{

}

BigTurret::BigTurret(D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 70, 70);

	turret::Init("Ingame_Enemy_Yamato_BigTurret", objectInfo);

	m_Info->m_centerPos = D3DXVECTOR3(m_image->info.Width / 2, m_image->info.Height / 2 - 20, 0.0f);

	m_attackTime = timeGetTime() + 2000;
}

void BigTurret::Attack()
{
}
