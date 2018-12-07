#pragma once
#include "cEnemy.h"
class cEnemyPlane :
	public cEnemy
{
protected:
	int m_attackCount;
	int m_attackPattern;
public:
	cEnemyPlane();
	virtual ~cEnemyPlane();

	virtual void Render()	override;
};

