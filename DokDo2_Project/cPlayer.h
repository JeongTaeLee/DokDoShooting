#pragma once
#include "cGameObject.h"
class cPlayer :
	public cGameObject
{
protected:

	int m_hp;
	int m_powerUp;
	int m_coinUp;
	int m_attackCount;

	float m_speed;

	D3DXVECTOR2 m_dir;


	DWORD m_attackTime;
	DWORD m_reCreateTime;
	DWORD m_deadTime;
	DWORD m_nowTime;
public:
	cPlayer();
	virtual ~cPlayer();
	
	virtual void Init(D3DXVECTOR2 pos);
	virtual void Update() override;


	void Move();
	void Fire();
	void Animation();

	//virtual void Render()	override;

	virtual void CollisionCheck(cGameObject * object) override;


	const int GetHp()		{ return m_hp; }
	const int GetPowerUp()	{ return m_powerUp; }
	const int GetCoin()		{ return m_coinUp; }
};

