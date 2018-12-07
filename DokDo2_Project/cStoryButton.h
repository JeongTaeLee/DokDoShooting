#pragma once
#include "cButton.h"

class cScreen;
class cStoryButton :
	public cButton
{
private:
	cScreen * Screen;
public:
	cStoryButton();
	virtual ~cStoryButton();
	

	virtual void Init(D3DXVECTOR2 pos);
	virtual void Update()	override;
};

