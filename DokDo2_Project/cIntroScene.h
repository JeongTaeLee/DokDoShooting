#pragma once
#include "cScene.h"
class cIntroScene :
	public cScene
{
private:
	texture * m_backGround;
	texture * m_logoImage;


public:
	cIntroScene();
	~cIntroScene();

	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};

