#include "DXUT.h"
#include "cLoadingScene.h"


cLoadingScene::cLoadingScene()
{
}


cLoadingScene::~cLoadingScene()
{
}

void cLoadingScene::Init()
{
	m_loadingImage = IMAGEMANAGER->AddSingleImage("Loading_BackGround", "./Image/BackGround/Loading/7.png");

	LoadingStart = false;
	LoadingEnd = false;
}

void cLoadingScene::Update()
{
	
	if (LoadingStart)
	{
		
#pragma region IntroLoading
		//IntroSceneResource
		IMAGEMANAGER->AddSingleImage("Intro_BackGround", "./Image/BackGround/Intro/IntroBackGround.png");
		IMAGEMANAGER->AddSingleImage("Intro_Logo", "./Image/Ui/LOGO/LOGO.png");
		
		//IntroButton
		IMAGEMANAGER->AddListImage("Intro_StartButton", L"./Image/Ui/IntroScene/Button/Start0%d.png", 3);
		IMAGEMANAGER->AddListImage("Intro_ManualButton", L"./Image/Ui/IntroScene/Button/Manual0%d.png", 2);
		IMAGEMANAGER->AddListImage("Intro_RankingButton", L"./Image/Ui/IntroScene/Button/Ranking0%d.png", 2);
		IMAGEMANAGER->AddListImage("Intro_StoryButton", L"./Image/Ui/IntroScene/Button/Story0%d.png", 2);
		IMAGEMANAGER->AddListImage("Intro_DevloperButton", L"./Image/Ui/IntroScene/Button/Devloper0%d.png", 2);
		IMAGEMANAGER->AddListImage("Intro_ExitButton", L"./Image/Ui/IntroScene/Button/Exit0%d.png", 2);

		//IntroScreen;
		IMAGEMANAGER->AddSingleImage("Intro_ManualScreen", "./Image/Ui/IntroScene/Screen/ManualScreen.png");
		IMAGEMANAGER->AddSingleImage("Intro_RankingScreen", "./Image/Ui/IntroScene/Screen/RankingScreen.png");
		IMAGEMANAGER->AddSingleImage("Intro_DevloperScreen", "./Image/Ui/IntroScene/Screen/DevloperScreen.png");
		IMAGEMANAGER->AddSingleImage("Intro_StoryScreen", "./Image/Ui/IntroScene/Screen/StoryScreen.png");
#pragma endregion IntroLoading

#pragma region CutScene
		//CutScene
		IMAGEMANAGER->AddListImage("CutScene_DokDo", L"./Image/Ui/CutScene/Untitled-%d.png",5);
#pragma endregion CutScene

#pragma region BasicUi
		//BasicButton
		IMAGEMANAGER->AddListImage("Button_XButton", L"./Image/Ui/PublicButton/Exit/ExitButton0%d.png", 2);
#pragma endregion BasicUi


#pragma region InGame\
		// Explosions
		IMAGEMANAGER->AddListImage("Ingame_Explosions", L"./Image/Explosion/%d_1.png",27);


		//IngameBackGround
		IMAGEMANAGER->AddSingleImage("Ingame_FirstMap", "./Image/BackGround/Ingame/Map.png");
		IMAGEMANAGER->AddSingleImage("Ingame_FirstCloud", "./Image/BackGround/Ingame/Cloud01.png");
		IMAGEMANAGER->AddSingleImage("Ingame_SecondCloud", "./Image/BackGround/Ingame/Cloud02.png");

		//Ui
		IMAGEMANAGER->AddSingleImage("Ingame_InterfaceUi", "./Image/BackGround/Ingame/InterfaceUi.png");
		IMAGEMANAGER->AddListImage("Ingmae_StageMission", L"./Image/Ui/IngameScene/IngameMission/Stage0%d.png", 2);
		IMAGEMANAGER->AddListImage("Ingame_Cursor", L"./Image/Ui/cCursor/cursor0%d.png", 2);
		IMAGEMANAGER->AddSingleImage("Ingame_GameStart", "./Image/Ui/IngameScene/GameStart/GameStart.png");
		//IngameObject

		//Player
		IMAGEMANAGER->AddListImage("Ingame_Player_AirPlane", L"./Image/Player/Player_AirPlane/Player_%d.png", 7);
		IMAGEMANAGER->AddSingleImage("Ingame_Player_Ship", "./Image/Player/Player_Ship/PlayerShip.png");
		IMAGEMANAGER->AddSingleImage("Ingmae_Player_Ship_Turret", "./Image/Player/Player_Ship/PlayerTurret.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Player_Ship_Hit", "./Image/Player/Player_Ship/PlayerShipHit.png");
		IMAGEMANAGER->AddListImage("Ingame_Player_wtExplosion", L"./Image/Player/Player_Ship/wtExplosion/wtExplosion0%d.png",3);
		IMAGEMANAGER->AddListImage("Ingame_Player_Missile", L"./Image/Player/Player_Ship/Missile/Missile0%d.png", 4);
		

		//Enemy
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Ship01", "./Image/Enemy/Ship/EnemyShip01/Enemy.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Ship01_Hit", "./Image/Enemy/Ship/EnemyShip01/EnemyHit.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Ship01_Turret", "./Image/Enemy/Ship/EnemyShip01/Turret.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Ship02", "./Image/Enemy/Ship/EnemyShip02/Enemy.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Ship02_Turret", "./Image/Enemy/Ship/EnemyShip02/Turret.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Ship02_Hit", "./Image/Enemy/Ship/EnemyShip02/Hit.png");

		// Boss
		// Yamato
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Yamato", "./Image/Enemy/Ship/Boss_Yamato/Yamato/Yamato.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Yamato_SmallTurret", "./Image/Enemy/Ship/Boss_Yamato/SmallTurret/SmallTurret.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Yamato_BigTurret", "./Image/Enemy/Ship/Boss_Yamato/BigTurret/BigTurret.png");
		
		


		//Enemy_AirPlane
		IMAGEMANAGER->AddListImage("Ingame_Enemy_Plane01", L"./Image/Enemy/AirPlane/Enemy_AirPlane01/1_%d.png", 20);
		IMAGEMANAGER->AddListImage("Ingame_Enemy_Plane03", L"./Image/Enemy/AirPlane/Enemy_AirPlane03/Enemy03_%d.png", 7);
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_MiddleBoss", "./Image/Enemy/AirPlane/Enemy_AirPlane05/StageMiddle.png");

		//Enemy_Bullet
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Bullet01", "./Image/Enemy/Bullet/Bullet01.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Bullet02", "./Image/Enemy/Bullet/Bullet02.png");
		IMAGEMANAGER->AddSingleImage("Ingame_Enemy_Bullet03", "./Image/Enemy/Bullet/Bullet03.png");
#pragma endregion InGame
		LoadingEnd = true;
		LoadingStart = false;
	}

	
	if (LoadingEnd)
	{
		SCENEMANAGER->ChangeScene("CutScene");
	}
	
}


void cLoadingScene::Render()
{
	m_loadingImage->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	LoadingStart = true;
}

void cLoadingScene::Release()
{
}
