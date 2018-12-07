#pragma once
#include "cUi.h"
class cGameStart :
	public cUi
{
private:
	bool m_timeStart;

	int m_Alpha;

	DWORD m_nowTime;
public:
	cGameStart();
	virtual ~cGameStart();

	virtual void Update() override;
};

