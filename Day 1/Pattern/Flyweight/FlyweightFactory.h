#pragma once

#include <map>

class Flyweight;
class FlyweightContext;

class FlyweightFactory
{
public:
	static Flyweight* CreateFlyweight(int id, FlyweightContext& context);

private:
	static std::map<int, Flyweight*> m_ObjMap;
};

