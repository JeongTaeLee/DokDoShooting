#pragma once
#include "singleton.h"

class cGameStart;

class cGameManager :
	public singleton<cGameManager>
{
private:
	int m_nowStage;
	int m_nowScore;


	void Init();
	void Release();
public:
	cGameManager();
	virtual ~cGameManager();


	void Update();
	
	


	int & GetScore() { return m_nowScore; }
	int GetStage() { return m_nowStage; }
};

#define GAMEMANAGER cGameManager::GetInstance()