#pragma once
#include "cButton.h"
class cStartButton :
	public cButton
{
private:
	bool r;
public:
	cStartButton();
	virtual ~cStartButton();

	virtual void Init(D3DXVECTOR2 pos)	override;
	virtual void Update() override;
	//virtual void Render() override;
};

