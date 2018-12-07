#include "DXUT.h"
#include "cCutScene.h"


cCutScene::cCutScene()
{
	m_aniInfo = nullptr;
}


cCutScene::~cCutScene()
{
}

void cCutScene::Init()
{
	m_images = IMAGEMANAGER->FindListImage("CutScene_DokDo");
	m_nowImage = (*m_images)[0];

	m_CutTime = 0;
	m_CutCount = 0;


	m_aniInfo = new cAnimationInfo(3, 0);
}

void cCutScene::Update()
{
	if (m_CutTime < timeGetTime())
	{
		if (KEY_DOWN(VK_RETURN))
		{
			m_CutTime = timeGetTime() + 100;
			m_aniInfo->nowFrame = m_CutCount;
			if (m_CutCount < 5)
			{
				m_CutCount++;
				
				if (m_CutCount == 5)
				{
					IMAGEMANAGER->DeleteListImage("CutScene_DokDo");
					SCENEMANAGER->ChangeScene("IntroScene");
				}
			}
		}
	}

//	m_nowImage = (*m_images)[m_aniInfo->nowFrame];
}

void cCutScene::Render()
{
	if (m_CutCount == 4)
	{
		(*m_images)[4]->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	}
	else if (m_CutCount < 5)
	{
		for (int i = 0; i < m_CutCount + 1; i++)
		{
			(*m_images)[i]->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
		}
	}
}
void cCutScene::Release()
{
	SAFE_DELETE(m_aniInfo);
}


