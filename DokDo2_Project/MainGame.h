#pragma once
class MainGame
{
private:
	
public:
	MainGame();
	~MainGame();

	void Init();
	void Release();
	void Update();
	void Render();

	void ResetDevice();
	void LostDevice();
};

