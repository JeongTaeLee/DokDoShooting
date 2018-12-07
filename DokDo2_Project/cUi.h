#pragma once
#include "cGameObject.h"
class cUi :
	public cGameObject
{
public:
	cUi();
	virtual ~cUi();

	virtual void Init(const string & key, cAnimationInfo * aniInfo, cObjectInfo * objectInfo);
	virtual void Render()	override;
};

