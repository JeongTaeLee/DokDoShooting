#pragma once

enum AniState
{
	IDLE,
	LEFT,
	RIGHT,
	DEAD
};
struct cAnimationInfo
{
public:
	int maxFrame;
	int nowFrame;
	int idleFrame;

	int aniState;

	DWORD frameTime;
	DWORD nowTime;

	bool loopFrame;
	bool endFrame;
public:
	cAnimationInfo(int max, int idle, bool loop = true, DWORD frameTime = 0);
	~cAnimationInfo();

	void UpdateFrame();
};

