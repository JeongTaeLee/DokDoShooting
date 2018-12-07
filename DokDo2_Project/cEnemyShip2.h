#pragma once
#include "cEnemyShip.h"

class turret02 : public turret
{
public:
	turret02(D3DXVECTOR2 pos);
	virtual ~turret02();

	virtual void Attack()	override;
};

class cEnemyShip2 : public cEnemyShip
{
public:
	cEnemyShip2(D3DXVECTOR2 pos, int movePattern);
	virtual ~cEnemyShip2();

	virtual void Update()	override;
	void Fire();
	void Move();
	void Animation();

};

