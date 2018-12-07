#pragma once
#include "cEnemy.h"

class turret : public cEnemy {
public:
	texture * m_image;


	DWORD m_attackTime;

	int m_attackCount;

	turret()
	{
		m_image = nullptr;
		m_Info = nullptr;
		m_attackTime = 0;
		m_attackCount = 0;

	}

	void Init(const string & key, cObjectInfo * objectInfo) {
		m_image = IMAGEMANAGER->FindSingleImage(key);
		m_Info = objectInfo;
	}

	~turret()
	{
		SAFE_DELETE(m_Info);
	}

	virtual void Update()	override;
	virtual void Render()	override;

	virtual void Attack() PURE;
	
	virtual bool IsOutMap()	override;
	virtual void CollisionCheck(cGameObject * object)	override;
};

class cEnemyShip :
	public cEnemy
{
public:
	vector<turret*> m_turret;

	texture * m_nowWater;
	texture * m_waterWave;
	cAnimationInfo * m_waterAniInfo;
public:
	cEnemyShip();
	virtual ~cEnemyShip();

	virtual void Render() override;
};

