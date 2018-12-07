#include "DXUT.h"
#include "cBulletLib.h"
#include "cEnemyBullet.h"

void NwayBullet(const string & key, D3DXVECTOR2 startPos, D3DXVECTOR2 direction, int Amount, float angle, float speed)
{
	float rad_step = D3DXToRadian(angle);
	
	float rad = -Amount % 2 ? -Amount / 2 * rad_step : (-Amount / 2 + 0.5) * rad_step;


	for (int i = 0; i < Amount; i++, rad += rad_step)
	{
		float c = cos(rad), s = sin(rad);

		D3DXVECTOR2 dir = D3DXVECTOR2(direction.x * c - direction.y * s, direction.x * s + direction.y * c);
		D3DXVec2Normalize(&dir, &dir);

		cEnemyBullet * bullet = new cEnemyBullet(key, startPos, dir, speed);
		OBJECTMANAGER->AddObject(OBJECTTYPE::EBULLET, bullet);
	}

}

