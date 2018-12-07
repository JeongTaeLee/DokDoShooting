#pragma once
#include "singleton.h"

class cScene;

class cSceneManager :
	public singleton<cSceneManager>
{
private:
	map<string, cScene*> m_scenes;

	cScene * m_nowScene;
	cScene * m_nextScene;
public:
	cSceneManager();
	virtual ~cSceneManager();

	cScene * AddScene(const string & SceneName, cScene * scene);
	cScene * ChangeScene(const string &SceneName);
	
	void Update();
	void Render();
	void Release();
};

#define SCENEMANAGER cSceneManager::GetInstance()