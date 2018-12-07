#pragma once
#include "cButton.h"


class cScreen;

class cDevloperButton :
	public cButton
{
private:
	cScreen * Devloper;
public:
	cDevloperButton();
	~cDevloperButton();

	virtual void Init(D3DXVECTOR2 pos);
	virtual void Update()	override;
};

