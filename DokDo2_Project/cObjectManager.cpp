#include "DXUT.h"
#include "cObjectManager.h"
#include "cGameObject.h"
#include "MyLib.h"

cObjectManager::cObjectManager()
{
	
}


cObjectManager::~cObjectManager()
{
	Release();
}

cGameObject * cObjectManager::AddObject(int key, cGameObject * object)
{
	auto find = m_objects.find(key);

	if (find == m_objects.end())
	{
		DEBUG_LOG("Error! FAILED AddObject OBJECTKEY : " << key);
		DEBUG_LOG("comment : 오브젝트 키를 다시확인해주세요.");
		return nullptr;
	}
	if (object == nullptr)
	{
		DEBUG_LOG("Error! FAILED AddObject OBJECTKEY : " << key);
		DEBUG_LOG("comment : object가 nullptr 입니다.");
		return nullptr;
	}


	(*find->second).push_back(object);

	return object;
}

void cObjectManager::Init()
{
	m_objects.insert(make_pair(MAP,		new list<cGameObject*>));
	m_objects.insert(make_pair(ENEMY,	new list<cGameObject*>));
	m_objects.insert(make_pair(PLAYER,	new list<cGameObject*>));
	m_objects.insert(make_pair(EBULLET, new list<cGameObject*>));
	m_objects.insert(make_pair(PBULLET, new list<cGameObject*>));
	m_objects.insert(make_pair(ITEM,	new list<cGameObject*>));
	m_objects.insert(make_pair(UI,		new list<cGameObject*>));
	m_objects.insert(make_pair(END,		new list<cGameObject*>));
}

void cObjectManager::Update()
{
	//Update
	for (auto Iter : m_objects)
	{
		for (auto Iter02 : (*Iter.second))
		{
			if(Iter02)
				Iter02->Update();
		}
	}

	for (auto Iter : m_objects)
	{
		for (auto Iter02 = (*Iter.second).begin(); Iter02 != (*Iter.second).end();)
		{
			if ((*Iter02)->IsOutMap())
			{
				SAFE_DELETE((*Iter02));
				Iter02 = (Iter.second)->erase(Iter02);
				
			}
			else
				Iter02++;

		}
	}

	CollisionCheck();
}

void cObjectManager::Render()
{
	for (auto Iter : m_objects)
	{
		for (auto Iter02 : (*Iter.second))
		{
			if (Iter02)
				Iter02->Render();
		}
	}
}

void cObjectManager::Reset()
{
	for (auto Iter : m_objects)
	{
		for (auto Iter2 = (*Iter.second).begin(); Iter2 != (*Iter.second).end();)
		{
			SAFE_DELETE((*Iter2));
			(*Iter.second).erase(Iter2++);
		}
	}
}

void cObjectManager::Release()
{
	for (auto Iter : m_objects)
	{
		for (auto Iter02 : (*Iter.second))
		{
			SAFE_DELETE(Iter02);
		}
		(*Iter.second).clear();
		SAFE_DELETE(Iter.second);
	}
	m_objects.clear();
}

void cObjectManager::CollisionCheck()
{
	// PlayerBullet -> Enemy
	
	auto aPbullet = m_objects.find(PBULLET);
	auto aEnemy = m_objects.find(ENEMY);


	for (auto Iter = (*aPbullet).second->begin(); Iter != (*aPbullet).second->end();)
	{
		for (auto Iter02 = (*aEnemy).second->begin(); Iter02 != (*aEnemy).second->end();)
		{
			if (IsRectCollision((*Iter)->GetCollision(), (*Iter02)->GetCollision()))
			{
				if ((*Iter)->GetDelete() != true && (*Iter02)->GetDelete() != true)
				{
					(*Iter)->CollisionCheck((*Iter02));
					(*Iter02)->CollisionCheck((*Iter));
				}
			}
			Iter02++;
		}
		Iter++;
	}
	// 

	//EnemyBullet -> Player;

	auto eBullet = m_objects.find(EBULLET);
	auto player = OBJECTMANAGER->GetPlayer();

	if (player != nullptr)
	{
		for (auto Iter = (*eBullet).second->begin(); Iter != (*eBullet).second->end();)
		{
			if (IsRectCollision(player->GetCollision(), (*Iter)->GetCollision()))
			{
				(*Iter)->CollisionCheck(player);
				player->CollisionCheck((*Iter));
			}
			Iter++;
		}
	}

	//


	for (auto Iter : m_objects)
	{
		for (auto Iter02 = (*Iter.second).begin(); Iter02 != (*Iter.second).end();)
		{
			if ((*Iter02)->GetDelete())
			{
				SAFE_DELETE(*Iter02);
				Iter02 = (Iter.second)->erase(Iter02);
			}
			else
				Iter02++;
		}
	}
}
cGameObject * cObjectManager::GetPlayer()
{
	auto find = m_objects.find(PLAYER);

	if ((*find->second).size() == 0)
		return nullptr;

	auto player = (*find->second).begin();

	if ((*player) == nullptr)
		nullptr;

	return (*player);
}

list<cGameObject*> * cObjectManager::GetGameObject(int objType)
{
	auto find = m_objects.find(objType);

	if (find == m_objects.end())
	{
		DEBUG_LOG("Error! FAILED GetGameObject OBJECTKEY : " << objType);
		DEBUG_LOG("comment : 오브젝트를 찾을 수 없습니다");
		return nullptr;
	}


	return find->second;
}
