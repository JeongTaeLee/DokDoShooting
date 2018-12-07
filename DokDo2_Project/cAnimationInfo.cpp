#include "DXUT.h"
#include "cAnimationInfo.h"




cAnimationInfo::cAnimationInfo(int max, int idle, bool loop, DWORD Time)
	:maxFrame(max), nowFrame(0), idleFrame(idle), loopFrame(loop), endFrame(false), frameTime(Time), nowTime(0), aniState(IDLE)
{
}

cAnimationInfo::~cAnimationInfo()
{
}

void cAnimationInfo::UpdateFrame()
{

		if (nowFrame != maxFrame)
		{
			nowFrame++;
		}
		else
		{
			if (loopFrame)
				nowFrame = 0;
			else
			{
				if (endFrame == false)
					endFrame = true;
			}
		}
}
