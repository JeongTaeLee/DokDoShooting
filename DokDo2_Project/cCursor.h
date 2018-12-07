#pragma once
#include "cUi.h"
class cCursor :
	public cUi
{
private:
	POINT m_mousePos;
public:
	cCursor();
	virtual ~cCursor();

	virtual void Update() override;
};

