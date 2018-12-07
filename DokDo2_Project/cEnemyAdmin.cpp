#include "DXUT.h"
#include "cEnemyAdmin.h"

#include "cEnemyShip1.h"
#include "cEnemyShip2.h"

#include "cEnemyPlane01.h"
#include "cEnemyPlane03.h"
#include "cStage01Middle.h"
#include "cYamato.h"


cEnemyAdmin::cEnemyAdmin()
{
	m_waveCount = 0;
	m_createTime = 0;
	m_createCount = 0;
}


cEnemyAdmin::~cEnemyAdmin()
{
}

void cEnemyAdmin::Update()
{
	CreateEnemy01();
}

void cEnemyAdmin::CreateEnemy01()
{

	switch (m_waveCount)
	{
	case 0:
	{
		//Yamato(D3DXVECTOR2(GAMESIZELEFT + 800, CENTERSCREENY - 200), 0, 0);
		//EPlane01Double(D3DXVECTOR2(CENTERSCREENX, - 50), 5, 400, 1000);
		EShip01Side(D3DXVECTOR2(GAMESIZELEFT - 100, CENTERSCREENY - 150), 1, 10, 2000);
		break;
	}
	case 1:
		EShip02Top(D3DXVECTOR2(CENTERSCREENX, -50), 1, 0, 0);
		break;
	case 2:
		EPlane01Sied(D3DXVECTOR2(GAMESIZELEFT - 50, 400), 5,600, 2000);
		//EShip01Side(D3DXVECTOR2(GAMESIZERIGHT + 100, CENTERSCREENY - 300), 1, 10, 2000);
		break;
	case 3:
		EPlane01Sied(D3DXVECTOR2(GAMESIZERIGHT + 50, 400), 5, 600, 500);
		break;
	case 4:
		EPlane03Side(D3DXVECTOR2(GAMESIZELEFT - 50, 150), 1, 0, 2000);
		break;
	case 5:
		EPlane01Top(D3DXVECTOR2(CENTERSCREENX + 150, -50), 5, 400, 1000);
		break;
	case 6:
		EPlane01Top(D3DXVECTOR2(CENTERSCREENX + 100, -50), 5, 400, 4000);
		break;
	case 7:
		EShip01Side(D3DXVECTOR2(GAMESIZERIGHT + 100, 200), 1, 400, 2000);
		break;
	case 8:
		EPlane01Top(D3DXVECTOR2(CENTERSCREENX - 100, -50), 5, 400, 2000);
		break;
	case 9 :
		EPlane03Side(D3DXVECTOR2(GAMESIZERIGHT + 50, 150), 1, 0, 1000);
		break;
	case 10:
		EPlane01Top(D3DXVECTOR2(CENTERSCREENX - 150, -50), 5, 400, 6000);
		break;
	case 11:
		EShip01Double(D3DXVECTOR2(CENTERSCREENX - 200, -100), D3DXVECTOR2(CENTERSCREENX + 200, -100), 1, 0, 0);
		break;
	case 12:
		EStage01Middle(0, 1000);
		break;
	case 13:
		EShip02Top(D3DXVECTOR2(GAMESIZELEFT + 100, -50), 1, 0, 0);
		break;
	case 14:
		EShip02Top(D3DXVECTOR2(GAMESIZERIGHT - 100, -50), 1, 0, 1000);
		break;
	case 15:
		EPlane01Top(D3DXVECTOR2(GAMESIZELEFT + 200, -50), 5, 400, 500);
		break;
	case 16:
		EPlane01Top(D3DXVECTOR2(GAMESIZERIGHT - 200, -50), 5, 400, 500);
		break;
	case 17:
		break;

	}
}

void cEnemyAdmin::EShip01Side(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyShip1 * enemy = new cEnemyShip1(pos, 1);
			OBJECTMANAGER->AddObject(ENEMY, enemy);

			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::EShip01Double(D3DXVECTOR2 pos01, D3DXVECTOR2 pos02, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyShip1 * enemy = new cEnemyShip1(D3DXVECTOR2(pos01.x, pos01.y), 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			enemy = new cEnemyShip1(D3DXVECTOR2(pos02.x, pos02.y), 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			//enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x - 100, pos.y), 0);
			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::EShip02Top(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyShip2 * enemy = new cEnemyShip2(D3DXVECTOR2(pos.x, pos.y), 1);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			//enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x - 100, pos.y), 0);
			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::Yamato(D3DXVECTOR2 pos, DWORD createTime, DWORD endTime)
{
	if (OBJECTMANAGER->GetGameObject(OBJECTTYPE::ENEMY)->size() == 0)
	{
		cYamato * enemy = new cYamato(pos);
		OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);
		m_createCount++;
	}
}

void cEnemyAdmin::EPlane01Double(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyPlane * enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x + 300, pos.y), 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);
			enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x - 300, pos.y), 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			//enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x - 100, pos.y), 0);
			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::EPlane01Sied(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyPlane * enemy = new cEnemyPlane01(pos, 1);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::EPlane01Top(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyPlane * enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x, pos.y), 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			//enemy = new cEnemyPlane01(D3DXVECTOR2(pos.x - 100, pos.y), 0);
			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::EPlane03Side(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < Amount)
		{
			m_createTime = timeGetTime() + createTime;

			cEnemyPlane03 * enemy = new cEnemyPlane03(pos, 0);
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			m_createCount = 0;
			m_waveCount++;
			m_createTime = timeGetTime() + endTime;
		}
	}
}

void cEnemyAdmin::EStage01Middle(DWORD createTime, DWORD endTime)
{
	if (m_createTime < timeGetTime())
	{
		if (m_createCount < 1)
		{
			m_createTime = timeGetTime() + createTime;

			cStage01Middle * enemy = new cStage01Middle(D3DXVECTOR2(CENTERSCREENX, -300));
			OBJECTMANAGER->AddObject(OBJECTTYPE::ENEMY, enemy);

			m_createCount++;
			//DEBUG_LOG("in" << m_createCount);
		}
		else
		{
			auto Iter = OBJECTMANAGER->GetGameObject(ENEMY);

			if (Iter->size() == 0)
			{
				m_createCount = 0;
				m_waveCount++;
				m_createTime = timeGetTime() + endTime;
			}
		}
	}
}


