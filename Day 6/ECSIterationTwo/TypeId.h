#pragma once

const int INVAID_TYPE_ID = -1;

template<typename T>
class TypeId
{
public:

	template<typename U>
	static const int Get()
	{
		static const int id{ m_typeCount++ };
		return id;
	}

	//static const int Get()
	//{
	//	return m_typeCount;
	//}

private:

	static int m_typeCount;
};

