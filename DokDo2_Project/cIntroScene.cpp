#include "DXUT.h"
#include "cIntroScene.h"
#include "cButton.h"
#include "cManualButton.h"
#include "cRankingButton.h"
#include "cDevloperButton.h"
#include "cStoryButton.h"
#include "cExitButton.h"
#include "cStartButton.h"
#include "cXButton.h"


cIntroScene::cIntroScene()
{
}


cIntroScene::~cIntroScene()
{
}

void cIntroScene::Init()
{
	OBJECTMANAGER->Reset();

	m_backGround = IMAGEMANAGER->FindSingleImage("Intro_BackGround");
	m_logoImage = IMAGEMANAGER->FindSingleImage("Intro_Logo");

	
	cButton * Manual = new cManualButton;
	Manual->Init(D3DXVECTOR2(0, 200));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manual);
	Manual = nullptr;

	Manual = new cRankingButton;
	Manual->Init(D3DXVECTOR2(0, 315));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manual);
	Manual = nullptr;

	Manual = new cStoryButton;
	Manual->Init(D3DXVECTOR2(0, 430));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manual);
	Manual = nullptr;

	Manual = new cDevloperButton;
	Manual->Init(D3DXVECTOR2(0, 545));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manual);
	Manual = nullptr;

	Manual = new cExitButton;
	Manual->Init(D3DXVECTOR2(0, 660));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manual);
	Manual = nullptr;

	Manual = new cStartButton;
	Manual->Init(D3DXVECTOR2(WINSIZEX / 2 - 150, -100));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, Manual);
	Manual = nullptr;


}

void cIntroScene::Update()
{
	OBJECTMANAGER->Update();
}

void cIntroScene::Render()
{
	m_backGround->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	m_logoImage->CenterRender(WINSIZEX / 2 + 300, WINSIZEY / 2 - 240);

	OBJECTMANAGER->Render();
}

void cIntroScene::Release()
{
}
