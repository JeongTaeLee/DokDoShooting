#include "DXUT.h"
#include "MainGame.h"
#include "cLoadingScene.h"
#include "cIntroScene.h"
#include "cCutScene.h"
#include "cStage01.h"



MainGame::MainGame()
{
	srand(time(NULL));
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	OBJECTMANAGER->Init();

	SCENEMANAGER->AddScene("LoadingScene", new cLoadingScene);
	SCENEMANAGER->AddScene("IntroScene", new cIntroScene);
	SCENEMANAGER->AddScene("CutScene", new cCutScene);
	SCENEMANAGER->AddScene("Stage01", new cStage01);

	SCENEMANAGER->ChangeScene("LoadingScene");
	
}

void MainGame::Release()
{
	cObjectManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
	cImageManager::ReleaseInstance();
	cTextManager::ReleaseInstance();
	cGameManager::ReleaseInstance();
	cInputManager::ReleaseInstance();
}

void MainGame::Update()
{
	SCENEMANAGER->Update();
}

void MainGame::Render()
{
	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();

	IMAGEMANAGER->End();
}

void MainGame::ResetDevice()
{
	IMAGEMANAGER->ResetDevice();
}

void MainGame::LostDevice()
{
	IMAGEMANAGER->LostDevice();
}
