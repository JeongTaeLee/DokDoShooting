#pragma once
class cEnemyAdmin
{
private:
	int m_waveCount;
	int m_createCount;

	DWORD m_createTime;
public:
	cEnemyAdmin();
	~cEnemyAdmin();

	void Update();

	void CreateEnemy01();

//Ship
	void EShip01Side(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime);
	void EShip01Double(D3DXVECTOR2 pos01, D3DXVECTOR2 pos02, int Amount, DWORD createTime, DWORD endTime);
	void EShip02Top(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime);
	
	void Yamato(D3DXVECTOR2 pos, DWORD createTime, DWORD endTime);

//AirPlane
	void EPlane01Double(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime);
	void EPlane01Sied(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime);
	void EPlane01Top(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime);
	void EPlane03Side(D3DXVECTOR2 pos, int Amount, DWORD createTime, DWORD endTime);
	void EStage01Middle(DWORD createTime, DWORD endTime);
	
		
};



