// Visitor Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "TestVisitor.h"
#include "ElementOne.h"
#include "ElementTwo.h"


int main()
{
	ElementOne elementOne;
	ElementTwo elementTwo;
	TestVisitor testVisitor;

	std::vector<IElement*> elements = {
	  &elementOne,
	  &elementTwo
	};


	for (IElement* element : elements) {
		element->Accept(testVisitor);
	}
}


