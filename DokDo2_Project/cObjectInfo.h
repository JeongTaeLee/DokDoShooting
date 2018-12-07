#pragma once

struct cObjectInfo
{
public:
	D3DXVECTOR2 m_pos;
	D3DXVECTOR3 m_centerPos;
	D3DCOLOR	m_color;
	bool		initCenter;
	
	float m_collisionX;
	float m_collisionY;
	float m_rot;

	RECT	m_collision;

public:
	cObjectInfo(D3DXVECTOR2 pos, float m_CollisionX = 0.0f, float m_CollisionY = 0.0f, bool Initc = true, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	~cObjectInfo();

	void Update();
};

