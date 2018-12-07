#pragma once
#include "cScene.h"
class cCutScene :
	public cScene
{
private:
	vector<texture*> *	m_images;
	texture *			m_nowImage;

	cAnimationInfo * m_aniInfo;
	DWORD				m_CutTime;
	int					m_CutCount;

public:
	cCutScene();
	virtual ~cCutScene();

	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};

