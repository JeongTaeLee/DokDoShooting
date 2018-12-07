#include "DXUT.h"
#include "cPlayerShip.h"
#include "cShipMissile.h"


cPlayerShip::cPlayerShip()
{
}


cPlayerShip::~cPlayerShip()
{
	Release();
}

void cPlayerShip::Init(D3DXVECTOR2 pos)
{
	cObjectInfo* objectInfo = new cObjectInfo(pos, 15 , 15);
	
	cGameObject::Init("Ingame_Player_Ship", objectInfo, nullptr);

	m_speed = 300;

	m_wtImages = IMAGEMANAGER->FindListImage("Ingame_Player_wtExplosion");
	m_wtImage = (*m_wtImages)[0];

	m_wtAniInfo = new cAnimationInfo(2, 0, true, 200);

	m_hitImage = IMAGEMANAGER->FindSingleImage("Ingame_Player_Ship_Hit");
	m_turretImage = IMAGEMANAGER->FindSingleImage("Ingmae_Player_Ship_Turret");

	m_turretInfo = new cObjectInfo(D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y - 90), 10, 10);
	m_turretInfo->m_centerPos = D3DXVECTOR3(m_turretImage->info.Width / 2, m_turretImage->info.Height / 2 + 10, 0.0f);
	//m_turretInfo->m_rot = 0;
}

void cPlayerShip::Update()
{
	GetCursorPos(&m_mousePos);
	ScreenToClient(DXUTGetHWND(), &m_mousePos);


	Animation();

	//DEBUG_LOG("left : " << m_Info->m_collision.left << "Right : " << m_Info->m_collision.right);
	//DEBUG_LOG("top : " << m_Info->m_collision.top << "bottom : " << m_Info->m_collision.bottom);

	if (m_deadTime != 0)
	{
		if (m_deadTime < timeGetTime())
		{
			m_reCreateTime = (timeGetTime() + 5000);
			m_deadTime = 0;
		}
	}
	else
	{
		Move();
		Fire();

		
	}

	if (m_reCreateTime != 0)
	{ 
		if (m_nowTime < timeGetTime())
		{
			m_nowTime = timeGetTime() + 100;
			if (m_Info->m_color != D3DCOLOR_ARGB(255, 255, 255, 255))
				m_Info->m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
			else
				m_Info->m_color = D3DCOLOR_ARGB(0, 255, 255, 255);
		}

		if (m_reCreateTime < timeGetTime())
		{
			m_reCreateTime = 0;
			m_Info->m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
		}
	}

	
	m_turretInfo->Update();
	m_Info->m_collision = m_turretInfo->m_collision;


}

void cPlayerShip::Render()
{
	if (m_deadTime == 0)
	{
		m_wtImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, 0.0f, m_Info->m_centerPos);
		m_nowImage->Render(m_Info->m_pos.x, m_Info->m_pos.y, 1.0f, 0.0f, m_Info->m_centerPos, m_Info->m_color);
		m_turretImage->Render(m_turretInfo->m_pos.x, m_turretInfo->m_pos.y, 1.0f, m_turretInfo->m_rot, m_turretInfo->m_centerPos, m_Info->m_color);
	}
}

void cPlayerShip::Release()
{
	SAFE_DELETE(m_turretInfo);
	SAFE_DELETE(m_wtAniInfo);
}

void cPlayerShip::Move()
{
	if (INPUTMANAGER->KeyPress('A'))
	{
	
		if (m_Info->m_pos.x - (m_speed * DXUTGetElapsedTime()) > GAMESIZELEFT + 30)
			m_Info->m_pos.x -= m_speed * DXUTGetElapsedTime();
	}
	if (INPUTMANAGER->KeyPress('D'))
	{

		if (m_Info->m_pos.x + (m_speed * DXUTGetElapsedTime()) < GAMESIZERIGHT - 30)
			m_Info->m_pos.x += m_speed * DXUTGetElapsedTime();
	}
	/*
	if (INPUTMANAGER->KeyPress('W'))
	{
		if (m_Info->m_pos.y - (m_speed * DXUTGetElapsedTime()) > GAMESIZETOP + 40)
			m_Info->m_pos.y -= m_speed * DXUTGetElapsedTime();
	}
	if (INPUTMANAGER->KeyPress('S'))
	{
		if (m_Info->m_pos.y + (m_speed * DXUTGetElapsedTime()) < GAMESIZEBOTTOM - 40)
			m_Info->m_pos.y += (m_speed * DXUTGetElapsedTime());
	}
	*/

	m_turretInfo->m_pos = D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y -90);
}

void cPlayerShip::Fire()
{
	if (m_attackTime < timeGetTime())
	{
		m_attackTime = timeGetTime() + 100;

		if (GetAsyncKeyState(VK_LBUTTON))
		{

			cShipMissile * missile = new cShipMissile(D3DXVECTOR2(m_Info->m_pos.x, m_Info->m_pos.y - 90), D3DXVECTOR2(m_mousePos.x, m_mousePos.y), 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::PBULLET, missile);

		}
	}

	D3DXVECTOR2 tempDirection = D3DXVECTOR2(0, -1);
	D3DXVECTOR2 turretDirection = D3DXVECTOR2(m_mousePos.x, m_mousePos.y) - m_turretInfo->m_pos;

	D3DXVec2Normalize(&tempDirection, &tempDirection);
	D3DXVec2Normalize(&turretDirection, &turretDirection);

	m_turretInfo->m_rot = (float)acos(D3DXVec2Dot(&tempDirection, &turretDirection));

	if (m_mousePos.x < m_turretInfo->m_pos.x)
		m_turretInfo->m_rot *= -1;
}

void cPlayerShip::Animation()
{
	if (m_wtAniInfo->nowTime < timeGetTime())
	{
		m_wtAniInfo->nowTime = m_wtAniInfo->frameTime + timeGetTime();

		m_wtAniInfo->UpdateFrame();
	}

	m_wtImage = (*m_wtImages)[m_wtAniInfo->nowFrame];

	
}
