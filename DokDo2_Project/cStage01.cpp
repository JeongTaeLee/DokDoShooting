#include "DXUT.h"
#include "cStage01.h"
#include "cFirstMap.h"
#include "cFirstCloud.h"
#include "cSecondMap.h"
#include "cUi.h"
#include "cInterfaceUi.h"
#include "cPlayerShip.h"
#include "cCursor.h"
#include "cIngameMission.h"
#include "cGameStart.h"
#include "cEnemyAdmin.h"

#include "cPlayer.h"

cStage01::cStage01()
{
	enemyCreate = nullptr;
}


cStage01::~cStage01()
{
}

void cStage01::Init()
{
	ShowCursor(false);

	OBJECTMANAGER->Reset();
	cMap * map = new cFirstMap;
	OBJECTMANAGER->AddObject(OBJECTTYPE::MAP, map);
	map = nullptr;


	cPlayer * object = new cPlayerShip;
	object->Init(D3DXVECTOR2(CENTERSCREENX, 760));
	OBJECTMANAGER->AddObject(OBJECTTYPE::PLAYER, object);

	cUi * Ui = new cInterfaceUi;
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Ui);

	Ui = new cIngameMission;
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Ui);

	Ui = new cCursor;
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Ui);

	Ui = new cGameStart;
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Ui);

	enemyCreate = new cEnemyAdmin;
	m_startTime = timeGetTime() + 2000;
	
}

void cStage01::Update()
{
	
	INPUTMANAGER->Update();
	OBJECTMANAGER->Update();
	if (m_startTime < timeGetTime())
	{
		enemyCreate->Update();
	}
}

void cStage01::Render()
{
	OBJECTMANAGER->Render();
}

void cStage01::Release()
{
	
	SAFE_DELETE(enemyCreate);
	ShowCursor(true);
}
