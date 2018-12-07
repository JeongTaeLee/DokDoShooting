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
		DEBUG_LOG("comment : �̹� �����ϴ� Scene �Դϴ�.");
		return nullptr;
	}
	
	if (scene == nullptr)
	{
		DEBUG_LOG("Error! Failed AddScene Scene Name : " << SceneName);
		DEBUG_LOG("comment :  Scene�� nullptr �Դϴ�");
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
		DEBUG_LOG("comment : Scene�� �������� �ʽ��ϴ�");
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
