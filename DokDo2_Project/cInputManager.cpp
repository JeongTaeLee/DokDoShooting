#include "DXUT.h"
#include "cInputManager.h"


void cInputManager::Init()
{
	memset(m_nowKeyState, 0, sizeof(m_nowKeyState));
	memset(m_oldKeyState, 0, sizeof(m_oldKeyState));
}

void cInputManager::Release()
{
}

cInputManager::cInputManager()
{
	Init();
}


cInputManager::~cInputManager()
{
	Release();
}

void cInputManager::Update()
{
	memcpy(m_oldKeyState, m_nowKeyState, sizeof(m_oldKeyState));
	memset(m_nowKeyState, 0, sizeof(m_nowKeyState));
	memset(m_keyMap, 0, sizeof(m_keyMap));


	GetKeyboardState(m_nowKeyState);

	for (int i = 0; i < 256; i++)
	{
		BYTE vKey = m_nowKeyState[i] & 0x80;
		m_nowKeyState[i] = (vKey) ? 1 : 0;

		int nOld = m_nowKeyState[i];
		int nNow = m_oldKeyState[i];

		if (1 == nNow && 0 == nOld)
			m_keyMap[i] = EINPUT_DOWN;
		else if (0 == nNow && 1 == nOld)
			m_keyMap[i] = EINPUT_UP;
		else if (nNow == 1 && nOld == 1)
			m_keyMap[i] = EINPUT_PRESS;
		else
			m_keyMap[i] = EINPUT_NONE;
	}
}
