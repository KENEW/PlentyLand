#include "stdafx.h"
#include "TimeManager.h"


CTimeManager::CTimeManager()
{
	oldTime = CURRENT_SEC;
	deltaTime = 0;
}


CTimeManager::~CTimeManager()
{
}

void CTimeManager::Update()
{
	deltaTime = CURRENT_SEC - oldTime;
	//map<string, TickData*>::iterator iter;
	CONTAINER_LOOP(iter, data)
	{
		if (iter->second->timer != TRASH_VAL)
		{
			iter->second->timer -= deltaTime;
		}
		if (iter->second->timer != TRASH_VAL && iter->second->timer <= 0)
		{
			iter->second->timer = TRASH_VAL;
		}
	}
	oldTime = CURRENT_SEC;
}

void CTimeManager::AddTick(string name, double delay)
{
	TickData* temp = new TickData;
	temp->startTick = CURRENT_SEC;
	temp->delay = temp->timer = delay;
	temp->isPause = false;

	Add(temp, name);
}

bool CTimeManager::CheckTick(string name, bool isContinue, double delay)
{
	if (isExist(name))
	{
		AddTick(name, delay);
		return CheckTick(name, isContinue);
	}
	else
	{
		if (data[name]->timer == TRASH_VAL)
		{
			if (isContinue)
			{
				data[name]->timer = data[name]->delay;
			}
			return true;
		}
	}
}

double CTimeManager::GetTick(string name)
{
	return data[name]->timer;
}

void CTimeManager::PauseTick(string name)
{
	data[name]->isPause = true;
}

void CTimeManager::PlayTick(string name)
{
	data[name]->isPause = false;
}

void CTimeManager::RestartTick(string name)
{
	data[name]->startTick = CURRENT_SEC;
	data[name]->timer = data[name]->delay;
}

