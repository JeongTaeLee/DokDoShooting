#pragma once
#include "cObject.h"

class cScene : public cObject
{
public:
	cScene();
	virtual ~cScene();

	virtual void Init()		PURE;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
	
	
};

