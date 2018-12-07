#pragma once
#include "cGameObject.h"

class cScreen;

class cButton :
	public cGameObject
{
protected:
	
	POINT mousePos;

	bool m_onButton;
public:
	cButton();
	virtual ~cButton();

	virtual void Init(D3DXVECTOR2 pos) PURE;
	virtual void Render() override;

	virtual void OnButton();
	virtual void OffButton();

	bool GetButtonState() { return m_onButton; }
};

