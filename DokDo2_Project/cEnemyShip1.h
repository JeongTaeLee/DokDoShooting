#pragma once
#include "cEnemyShip.h"

class turret01 : public turret
{


public:

	turret01(D3DXVECTOR2 pos);
	virtual ~turret01();

	virtual void Attack() override;
};


class cEnemyShip1 :
	public cEnemyShip
{
public:
	cEnemyShip1(D3DXVECTOR2 pos, int movePattern);
	virtual ~cEnemyShip1();

	virtual void Update()	override;

	void Move();
	void Animation();
	void Fire();
};

