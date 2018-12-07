#pragma once
#include "singleton.h"

enum OBJECTTYPE
{
	MAP,
	ENEMY,
	PLAYER,
	EBULLET,
	PBULLET,
	ITEM,
	UI,
	END
	
};


class cPlayer;
class cGameObject;

class cObjectManager :
	public singleton<cObjectManager>
{
private:
	cGameObject * m_player;
	map<int, list<cGameObject*>*> m_objects;

public:
	cObjectManager();
	virtual ~cObjectManager();

	cGameObject * AddObject(int key, cGameObject* object);

	void Init();
	void Update();
	void Render();
	void Reset();
	void Release();

	void CollisionCheck();

	cGameObject * GetPlayer();
	list<cGameObject*> * GetGameObject(int objType);

	
};

#define OBJECTMANAGER cObjectManager::GetInstance()