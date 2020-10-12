#pragma once

class ECS;

class ISystem
{


};

template<class T>
class System
{
	friend ECS;

public:
	System(ECS& ecs);

	static const int TYPE_ID;

	int GetId() { return m_id; }

private:

	ECS* m_ecs;
	int m_id;
};

template<class T>
System<T>::System(ECS& ecs)
	: m_ecs(&ecs)
	, m_id(-1)
{

}

template<class T>
const int System<T>::TYPE_ID = TypeId<ISystem>::Get<T>();

