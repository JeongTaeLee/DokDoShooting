#pragma once
#include "cGameObject.h"

class cXButton;

class cScreen :
	public cGameObject
{
private:
	//texture * m_screen; gmaeobject�� nowImage�� �̿���.
	cXButton * m_xButton;
public:

	cScreen();
	virtual ~cScreen();

	virtual void Init(const string &imageKey, D3DXVECTOR2 pos);
	virtual void Update() override;
};

