#pragma once
//#include "stdafx.h"
#include "Singleton.h"

template<typename child, typename ObjType, typename KeyType = int>
class CManager
	: public CSingleton<child>
{
protected:
	map<KeyType, ObjType*> data;

public:
	CManager()
	{

	}

	virtual ~CManager()
	{
		Release();
	}

	void Release()
	{
		for (map<KeyType, ObjType*>::iterator iter = data.begin(); iter != data.end(); iter++)
		{
			DELETE_S(iter->second);
		}
		data.clear();
	}

protected:
	bool isExist(KeyType key)
	{
		return (data.find(key) != data.end());
	}

	ObjType* Add(ObjType* Object, KeyType key = data.size())
	{
		data.insert(make_pair(key, Object));

		return Object;
	}

	ObjType* Load(KeyType key, ObjType* obj = nullptr)
	{
		if (isExist(key))
		{
			return data[key];
		}
		else
		{
			if (obj != nullptr)
			{
				return Add(obj, key);
			}
			return nullptr;
		}
	}

};

