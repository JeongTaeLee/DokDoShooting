#pragma once
#include "cButton.h"



class cXButton :
	public cButton
{
private:

public:
	cXButton();
	~cXButton();

	virtual void Init(D3DXVECTOR2 pos) override;
	virtual void Update() override;

	virtual void OnButton() override;
	virtual void OffButton()override;
};

