#include "DXUT.h"
#include "cSceneManager.h"
#include "cScene.h"

cSceneManager::cSceneManager()
{
	m_nowScene = nullptr;
	m_nextScene = nullptr;
}


cSceneManager::~cSceneManager()
{
	Release();
}

cScene * cSceneManager::AddScene(const string & SceneName, cScene * scene)
{
	auto find = m_scenes.find(SceneName);

	if (find != m_scenes.end())
	{
		DEBUG_LOG("Error! Failed AddScene Scene Name : " << SceneName);
		DEBUG_LOG("comment : 이미 존재하는 Scene 입니다.");
		return nullptr;
	}
	
	if (scene == nullptr)
	{
		DEBUG_LOG("Error! Failed AddScene Scene Name : " << SceneName);
		DEBUG_LOG("comment :  Scene이 nullptr 입니다");
		return nullptr;
	}

	m_scenes.insert(make_pair(SceneName, scene));

	return scene;
}

cScene * cSceneManager::ChangeScene(const string & SceneName)
{
	auto find = m_scenes.find(SceneName);

	if (find == m_scenes.end())
	{
		DEBUG_LOG("Error! FAILED ChangeScene! SceneName: " << SceneName);
		DEBUG_LOG("comment : Scene이 존재하지 않습니다");
		return nullptr;
	}

	m_nextScene = find->second;

	return m_nextScene;
}

void cSceneManager::Update()
{
	if (m_nextScene)
	{
		if (m_nowScene)
		{
			m_nowScene	->Release();
			m_nowScene	= nullptr;
		}
		m_nextScene	->Init();
		m_nowScene	= m_nextScene;
		m_nextScene = nullptr;
	}
	else
		m_nowScene->Update();
}

void cSceneManager::Render()
{
	if (m_nowScene != nullptr)
		m_nowScene -> Render();
}

void cSceneManager::Release()
{
	for (auto Iter : m_scenes)
	{
		Iter.second->Release();
		SAFE_DELETE(Iter.second);
	}
	m_scenes.clear();
}
