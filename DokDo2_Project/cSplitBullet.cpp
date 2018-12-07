#include "DXUT.h"
#include "cSplitBullet.h"
#include "cBulletLib.h"

cSplitBullet::cSplitBullet(D3DXVECTOR2 pos, D3DXVECTOR2 direction, int Amount, int Angle, DWORD Time)
	:m_splitAmount(Amount), m_splitAngle(Angle)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos, 0, 0);
	m_direction = direction;

	cBullet::Init("Ingame_Enemy_Bullet03", objectInfo, nullptr, 200, 0);

	m_splitTime = timeGetTime() + Time;
	m_colorTime = 0;
}

cSplitBullet::~cSplitBullet()
{
}

void cSplitBullet::Update()
{
	m_Info->m_pos += m_direction * (m_speed * DXUTGetElapsedTime());
	
	if (m_splitTime < timeGetTime())
	{
		if (OBJECTMANAGER->GetPlayer() != nullptr)
		{
			D3DXVECTOR2 bulletDirection = OBJECTMANAGER->GetPlayer()->GetPos() - m_Info->m_pos;
			D3DXVec2Normalize(&bulletDirection, &bulletDirection);

			NwayBullet("Ingame_Enemy_Bullet02", m_Info->m_pos, bulletDirection, m_splitAmount, m_splitAngle, 300);

			m_deleteObject = true;
		}
	}

	m_Info->Update();
	m_Info->m_rot += D3DXToRadian(10);

	if (m_colorTime < timeGetTime())
	{
		m_colorTime = timeGetTime() + 100;
		if (m_Info->m_color != D3DCOLOR_ARGB(255, 255, 255, 255))
			m_Info->m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
		else
			m_Info->m_color = D3DCOLOR_ARGB(100, 255, 255, 255);
	}

}
