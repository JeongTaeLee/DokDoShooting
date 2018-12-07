#pragma once
#include "cBullet.h"
class cSplitBullet :
	public cBullet
{
private:
	int m_splitAmount;
	float m_splitAngle;
	DWORD m_splitTime;
	DWORD m_colorTime;
public:
	cSplitBullet(D3DXVECTOR2 pos, D3DXVECTOR2 direction, int Amount, int Angle, DWORD Time );
	~cSplitBullet();

	virtual void Update()	override;
};

