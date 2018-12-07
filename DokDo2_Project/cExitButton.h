#pragma once
#include "cButton.h"
class cExitButton :
	public cButton
{
public:
	cExitButton();
	virtual ~cExitButton();

	virtual void Init(D3DXVECTOR2 pos)	override;
	virtual void Update()				override;
};

