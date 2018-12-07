#pragma once
#include "cGameObject.h"
class cExplosions :
	public cGameObject
{
public:
	cExplosions(D3DXVECTOR2 pos);
	virtual ~cExplosions();

	virtual void Update() override;
};

