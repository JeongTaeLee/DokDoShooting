#pragma once
#include "cUi.h"
class cInterfaceUi :
	public cUi
{
private:
	TCHAR * m_scoreText;
	TCHAR * m_scoreNum;
	TCHAR * m_hpText;
	TCHAR * m_powerText;
	TCHAR * m_coinText;

public:
	cInterfaceUi();
	virtual ~cInterfaceUi();
	
	virtual void Update() override;
	
	virtual void Render() override;


	virtual void Release() override;

};

