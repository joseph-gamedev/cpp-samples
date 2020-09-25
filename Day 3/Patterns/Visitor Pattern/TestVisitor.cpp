#include "TestVisitor.h"
#include "ElementOne.h"
#include <iostream>

void TestVisitor::Visit(ElementOne & element)
{
	std::cout << "ElementOne vist" << std::endl;
}

void TestVisitor::Visit(ElementTwo & element)
{
	std::cout << "ElementTwo vist" << std::endl;
}
