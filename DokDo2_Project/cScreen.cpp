#include "DXUT.h"
#include "cScreen.h"
#include "cXButton.h"


cScreen::cScreen()
{
}


cScreen::~cScreen()
{
}

void cScreen::Init(const string &imageKey, D3DXVECTOR2 pos)
{
	cObjectInfo * objectInfo = new cObjectInfo(pos);	

	cGameObject::Init(imageKey, objectInfo, nullptr);

	m_xButton = new cXButton;
	m_xButton->Init(D3DXVECTOR2(pos.x + 260, WINSIZEY / 2 - 280));
	OBJECTMANAGER->AddObject(OBJECTTYPE::UI, m_xButton);
}

void cScreen::Update()
{
	if (m_xButton->GetButtonState())
	{
		m_deleteObject = true;
	}
}
