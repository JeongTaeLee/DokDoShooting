#pragma once
#include "cMap.h"
class cFirstMap :
	public cMap
{
public:
	cFirstMap();
	virtual ~cFirstMap();

	virtual void Update() override;
};

