#pragma once

using namespace std;

#include <iostream>	
#include <memory>	
#include <tchar.h>
#include <list>
#include <vector>	
#include <map>	
#include <string>	
#include <algorithm>
#include <time.h>



#define g_Device DXUTGetD3D9Device()

#ifdef _DEBUG
#pragma comment (linker, "/entry:wWinMainCRTStartup /subsystem:console")
#define DEBUG_LOG(p) cout << p << endl
#define DEBUG_LOGW(p) wcout << p << endl
#else
#define DEBUG_LOG(p)
#define DEBUG_LOGW(p)
#endif // _DEBUG

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code)       ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

const int WINSIZEX = 1280;
const int WINSIZEY = 800;

const int GAMESIZELEFT		= 320;
const int GAMESIZERIGHT		= 1120;
const int GAMESIZETOP		= 0;
const int GAMESIZEBOTTOM	= 800;

const int CENTERSCREENX		= GAMESIZELEFT + (800 / 2);
const int CENTERSCREENY		= GAMESIZEBOTTOM / 2;

#include "MyLib.h"

#include "cImageManager.h"
#include "cSceneManager.h"
#include "cObjectManager.h"
#include "cTextManager.h"
#include "cGameManager.h"
#include "cInputManager.h"

// info
#include "cObjectInfo.h"
#include "cAnimationInfo.h"

