#include "DXUT.h"
#include "cEnemyShip.h"


cEnemyShip::cEnemyShip()
{
	m_waterAniInfo = nullptr;
	m_waterWave = nullptr;
}


cEnemyShip::~cEnemyShip()
{
	for (auto Iter : m_turret)
	{
		Iter->GetDelete() = true;
	}
	m_turret.clear();
}

void cEnemyShip::Render()
{
	if (m_waterWave != nullptr)
	{
		m_nowWater->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot, m_Info->m_color);
	}

	m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot,m_Info->m_centerPos, m_Info->m_color);

	
	for (auto Iter : m_turret)
	{
		Iter->m_image->Render(Iter->GetInfo()->m_pos.x, Iter->GetInfo()->m_pos.y, 1.0f, Iter->GetInfo()->m_rot, Iter->GetInfo()->m_centerPos, Iter->GetInfo()->m_color);
		//DEBUG_LOG(Iter->m_Info->m_rot);
	}
	
	if (m_hitCheck == true)
	{
		m_hitImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, m_Info->m_rot, m_Info->m_centerPos, m_Info->m_color);
		m_hitCheck = false;
	}
	
	
	
}

void turret::Update()
{
}

void turret::Render()
{
}

bool turret::IsOutMap()
{
	return false;
}

void turret::CollisionCheck(cGameObject * object)
{
}
