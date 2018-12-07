#pragma once
#include "cEnemyPlane.h"
class cEnemyPlane03 :
	public cEnemyPlane
{
public:
	cEnemyPlane03(D3DXVECTOR2 pos, int movePattern);
	virtual ~cEnemyPlane03();

	virtual void Update() override;
	void Move();
	void Fire();
	void Animation();
};

