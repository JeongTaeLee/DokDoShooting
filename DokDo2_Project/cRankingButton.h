#pragma once
#include "cButton.h"
class cRankingButton :
	public cButton
{
public:
	cRankingButton();
	virtual ~cRankingButton();

	virtual void Init(D3DXVECTOR2 pos)	 override;
	virtual void Update()				 override;
};

