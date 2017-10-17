#pragma once
#include "Manager.h"

struct TickData
{
	double startTick;
	double delay;		// ��ü ������
	double timer;		// �ʽð�
	bool isPause;
};

// Ÿ�̸Ӵ� ���ð��� �Ǹ� Ÿ�̸Ӱ� TRASH_VAL�� �ʱ�ȭ �Ǹ� �Ͻ����� �ȴ�.
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
