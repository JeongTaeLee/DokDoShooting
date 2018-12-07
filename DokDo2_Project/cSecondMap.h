#pragma once
#include "cMap.h"
class cSecondMap :
	public cMap
{
public:
	cSecondMap();
	virtual ~cSecondMap();

	virtual void Update() override;
};

