#pragma once
#include "cBullet.h"

enum PlayerBulletLevel {
	PLV1,
	PLV2,
	PLV3,
	PLV4
};

class cShipMissile :
	public cBullet
{
private:
	
public:
	cShipMissile(D3DXVECTOR2 pos, D3DXVECTOR2 direction, int LV = 0);
	virtual ~cShipMissile();

	virtual void Update()	override;
};

