#pragma once
#include "cScene.h"

class cGameStart;
class cEnemyAdmin;


class cStage01 :
	public cScene
{
private:
	cGameStart * startUi;
	cEnemyAdmin* enemyCreate;

	DWORD m_startTime;

public:
	cStage01();
	virtual ~cStage01();
	
	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override; 
	virtual void Release()	override;

};

