#pragma once
#include "cScene.h"

enum LodingType
{
	CutScene = 0,
	IntroScene,
	InGameScene,
	EndingScene
};


class cLoadingScene :
	public cScene
{
private:

	texture * m_loadingImage;
	bool LoadingStart;
	bool LoadingEnd;
public:
	cLoadingScene();
	virtual ~cLoadingScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

