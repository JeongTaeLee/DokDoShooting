#pragma once
#include "cGameObject.h"
class cBullet :
	public cGameObject
{
protected:
	D3DXVECTOR2 m_direction;

	float m_speed;
	float m_damage;
public:
	cBullet();
	~cBullet();

	virtual void Init(const string & key, cObjectInfo * objectInfo, cAnimationInfo * aniInfo, float speed, float damage);

	virtual void CollisionCheck(cGameObject * object) override;
	virtual bool IsOutMap()	override;

	int GetDamage() { return m_damage; };

};

