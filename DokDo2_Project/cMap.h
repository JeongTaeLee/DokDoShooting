#pragma once
#include "cGameObject.h"
class cMap :
	public cGameObject
{
protected:
	float m_scrool;
	float m_speed;
public:
	cMap();
	virtual ~cMap();

	virtual void Init(const string & key, D3DXVECTOR2 pos, const float m_speed);
	virtual void Render() override;
};

