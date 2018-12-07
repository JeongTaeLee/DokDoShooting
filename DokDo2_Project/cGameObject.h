#pragma once
#include "cObject.h"
class cGameObject :
	public cObject
{
protected:
	string				  m_tag;

	vector<texture *>	* m_images;
	texture				* m_nowImage;

	cObjectInfo			* m_Info;
	cAnimationInfo		* m_aniInfo;
	
	bool					m_shadow;
	bool					 m_deleteObject;
public:
	cGameObject();
	virtual ~cGameObject();
	
	virtual void Init(const string & key, cObjectInfo * objectInfo, cAnimationInfo * aniInfo);
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
	
	virtual bool IsOutMap();
	virtual void CollisionCheck(cGameObject * object);

	bool& GetDelete() { return m_deleteObject; }

	cObjectInfo * GetInfo() { return m_Info; }
	D3DXVECTOR2 & GetPos() { return m_Info->m_pos; }
	const RECT & GetCollision() { return m_Info->m_collision; }
	const string & GetTag() { return m_tag; }
};

