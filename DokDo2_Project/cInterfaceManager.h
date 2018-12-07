#pragma once
#include "singleton.h"
class cInterfaceManager :
	public singleton<cInterfaceManager>
{
public:
	cInterfaceManager();
	virtual ~cInterfaceManager();
};

