#include "FlyweightFactory.h"
#include "Flyweight.h"

std::map<int, Flyweight*> FlyweightFactory::m_ObjMap = {};

Flyweight* FlyweightFactory::CreateFlyweight(int id, FlyweightContext& context)
{
	if (!m_ObjMap[id])
	{
		m_ObjMap[id] = new Flyweight(context);
	}
	return m_ObjMap[id];
}