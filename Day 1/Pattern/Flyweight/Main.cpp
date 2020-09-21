
#include <iostream>
#include <map>
#include "Flyweight.h"
#include "FlyweightContext.h"
#include "FlyweightFactory.h"

int main()
{
	FlyweightContext context;
	Flyweight* obj1 = FlyweightFactory::CreateFlyweight(1, context);
	Flyweight* obj2 = FlyweightFactory::CreateFlyweight(2, context);

	delete obj1;
	delete obj2;
	std::cin.get();
}