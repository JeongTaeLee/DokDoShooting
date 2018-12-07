#pragma once
#include "cEnemyPlane.h"
class cStage01Middle :
	public cEnemyPlane
{
public:
	cStage01Middle(D3DXVECTOR2 pos);
	virtual ~cStage01Middle();

	virtual void Update() override;
	void Move();
	void Fire();
};

