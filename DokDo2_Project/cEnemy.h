#pragma once
#include "cGameObject.h"

class cEnemy :
	public cGameObject
{
protected:
	float m_hp;
	float m_speed;

	int	  m_movePattern;
	int   m_giveScore;
	
	DWORD m_attackTime;
	DWORD m_createTime;

	D3DXVECTOR2 m_direction;
	D3DXVECTOR2 * m_dirList;

	texture * m_hitImage;
	bool m_hitCheck;
public:
	cEnemy();
	virtual ~cEnemy();

	virtual void Init(const string & key, cObjectInfo * objectInfo, cAnimationInfo * aniInfo, float m_hp, float m_speed);

	virtual void CollisionCheck(cGameObject * object) override;

	virtual bool IsOutMap() override;

	float &  GetHp() { return m_hp; };
};

