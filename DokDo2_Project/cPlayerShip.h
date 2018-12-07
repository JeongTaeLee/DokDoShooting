#pragma once
#include "cPlayer.h"
class cPlayerShip :
	public cPlayer
{
private:
	vector<texture*> * m_wtImages;
	texture * m_wtImage;
	texture * m_hitImage;

	texture * m_turretImage;
	cObjectInfo * m_turretInfo;

	cAnimationInfo * m_wtAniInfo;

	POINT m_mousePos;

public:
	cPlayerShip();
	virtual ~cPlayerShip();

	virtual void Init(D3DXVECTOR2 pos) override;
	virtual void Update()	override;
	//virtual void Render()	override;
	virtual void Release()	override;

	virtual void Render()	override;

	void Move();
	void Fire();
	void Animation();
	

};

