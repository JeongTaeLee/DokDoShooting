#pragma once
#include "cUi.h"
class cIngameMission :
	public cUi
{
public:
	cIngameMission();
	virtual ~cIngameMission();

	virtual void Update() override;
};

