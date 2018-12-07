#include "DXUT.h"
#include "cGameManager.h"


void cGameManager::Init()
{
	m_nowStage = 1;
	m_nowScore = 0;
}

void cGameManager::Release()
{
}

cGameManager::cGameManager()
{
	Init();
}


cGameManager::~cGameManager()
{
	Release();
}



void cGameManager::Update()
{
}
