#pragma once
class cObject
{
public:
	cObject();
	virtual ~cObject();

	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;
};

