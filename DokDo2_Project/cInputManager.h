#pragma once
#include "singleton.h"
class cInputManager :
	public singleton<cInputManager>
{
private:
	enum EInputState {
		EINPUT_NONE = 0,
		EINPUT_DOWN,
		EINPUT_UP,
		EINPUT_PRESS,
		EINPUT_DBCLC
	};

	BYTE m_nowKeyState[256];
	BYTE m_oldKeyState[256];
	BYTE m_keyMap[256];


	void Init();
	void Release();
public:
	cInputManager();
	virtual ~cInputManager();

	void Update();
	
public:
	bool KeyDown(int nKey) { return m_keyMap[nKey] == EINPUT_DOWN;};
	bool KeyUp(int nKey) { return m_keyMap[nKey] == EINPUT_UP; };
	bool KeyPress(int nKey) { return m_keyMap[nKey] == EINPUT_PRESS; };
};

#define INPUTMANAGER cInputManager::GetInstance()