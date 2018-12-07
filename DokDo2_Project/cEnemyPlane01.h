#pragma once
#include "cEnemyPlane.h"
class cEnemyPlane01 :
	public cEnemyPlane
{

public:
	cEnemyPlane01(D3DXVECTOR2 pos, int movePattern);
	virtual ~cEnemyPlane01();

	virtual void Update()	override;
	
	void Move();
	void Fire();
	void Animation();
};

