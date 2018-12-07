#pragma once
#include "cEnemyShip.h"

class SmallTurret : public turret {
	
private:
	
public:
	SmallTurret(D3DXVECTOR2 pos);
	virtual ~SmallTurret() {}

	virtual void Attack()	override;
};

class BigTurret : public turret {
private:

public:
	BigTurret(D3DXVECTOR2 pos);
	virtual ~BigTurret() { }

	virtual void Attack()	override;
};

class cYamato :
	public cEnemyShip
{
public:
	cYamato(D3DXVECTOR2 pos);
	virtual ~cYamato();

	virtual void Update()	override;
	void Move();
	void Fire();
};

