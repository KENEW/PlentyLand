#pragma once
#include "Manager.h"
class CObjectManager :
	public CManager<CObjectManager, CObject>
{
private:
	<int> AddressOrder;
public:
	CObjectManager();
	~CObjectManager();

public:
	void AddObject(CObject* obj, int Address);
	void RenderAllObj();
};
#define OBJ_GET CObjectManager::GetInstance()
