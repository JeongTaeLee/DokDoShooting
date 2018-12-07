#include "DXUT.h"
#include "cEnemy.h"
#include "cBullet.h"
#include "cExplosions.h"


cEnemy::cEnemy()
{
	m_hp			= 0;
	m_speed			= 0;
	m_attackTime	= 0;
	
	m_movePattern	= 0;
	m_giveScore		= 0;

	m_direction = D3DXVECTOR2(0, 0);
	m_dirList = nullptr;
	
	m_hitImage = nullptr;
	m_hitCheck = false;

	m_createTime = timeGetTime();
}


cEnemy::~cEnemy()
{
	SAFE_DELETE(m_dirList);
}

void cEnemy::Init(const string & key, cObjectInfo * objectInfo, cAnimationInfo * aniInfo, float hp = 1.0f, float speed = 0.0f)
{
	cGameObject::Init(key, objectInfo, aniInfo);
	m_hp = hp;
	m_speed = speed;
}


void cEnemy::CollisionCheck(cGameObject * object)
{
	if (object->GetTag() == "PlayerBullet")
	{
		cBullet * temp = dynamic_cast<cBullet*>(object);	

		m_hp -= temp->GetDamage();

		if (m_hp <= 0)
		{
			m_deleteObject = true;
			GAMEMANAGER->GetScore() += m_giveScore;

			if (m_hitImage != nullptr)
				m_hitCheck = true;
			//m_nowImage = m_hitImage;
			
			cExplosions * explosions = new cExplosions(m_Info->m_pos);
			OBJECTMANAGER->AddObject(ENEMY, explosions);

		}
		else
		{
			if (m_hitImage != nullptr)
				m_hitCheck = true;
			else
				m_Info->m_color = D3DCOLOR_XRGB(255, 0, 0);
				//m_nowImage = m_hitImage;
		}
	}
}

bool cEnemy::IsOutMap()
{
	return (m_Info->m_pos.x < (GAMESIZELEFT - m_Info->m_collisionX * 4) ||
			m_Info->m_pos.x > (GAMESIZERIGHT + m_Info->m_collisionX * 4) ||
			m_Info->m_pos.y < (GAMESIZETOP - m_Info->m_collisionY * 4) ||
			m_Info->m_pos.y > (GAMESIZEBOTTOM + m_Info->m_collisionX * 4));
}
