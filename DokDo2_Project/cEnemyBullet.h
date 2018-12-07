#pragma once
#include "cBullet.h"
class cEnemyBullet :
	public cBullet
{
private:
public:
	cEnemyBullet(const string & key, D3DXVECTOR2 pos, D3DXVECTOR2 direction, float m_bulletSpeed);
	virtual ~cEnemyBullet();

	virtual void Update() override;
};

