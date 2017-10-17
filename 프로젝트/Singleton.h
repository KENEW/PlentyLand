#pragma once
#include "stdafx.h"
template <typename ObjType>
class CSingleton
{
private:
	static ObjType* m_Instace;

protected:
	string iden;

public:

	CSingleton()
	{
		m_Instace = nullptr;
		iden = "";
	}

	static ObjType* GetInstance()
	{
		if (!m_Instace)
		{
			m_Instace = new ObjType();
		}

		return m_Instace;
	}

	virtual ~CSingleton()
	{
		DELETE_S(m_Instace);
	}
};
template <typename ObjType> ObjType* CSingleton<ObjType>::m_Instace = 0;
