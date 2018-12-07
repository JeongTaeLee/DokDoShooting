#pragma once
#include "cButton.h"


class cScreen;
class cManualButton :
	public cButton
{
private:
	cScreen * Manaul;
public:
	cManualButton();
	virtual ~cManualButton();

	virtual void Init(D3DXVECTOR2 pos);
	virtual void Update()	override;
};

