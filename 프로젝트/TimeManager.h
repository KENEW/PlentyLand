#pragma once
#include "Manager.h"

struct TickData
{
	double startTick;
	double delay;		// 전체 딜레이
	double timer;		// 초시계
	bool isPause;
};

// 타이머는 제시각이 되면 타이머가 TRASH_VAL로 초기화 되며 일시중지 된다.
class CTimeManager :
	public CManager<CTimeManager, TickData, string>
{
private:
	double oldTime;

public:
	double deltaTime;

public:
	CTimeManager();
	~CTimeManager();

public:
	void Update();

	void AddTick(string name, double delay);
	bool CheckTick(string name, bool isContinue = true, double delay = TRASH_VAL);
	double GetTick(string name);

	void PauseTick(string name);
	void PlayTick(string name);
	void RestartTick(string name);
};
#define TIME_GET CTimeManager::GetInstance()
