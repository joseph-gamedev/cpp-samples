
#pragma once

class ElementOne;
class ElementTwo;

class IVisitor
{
public:
	virtual void Visit(ElementOne& element) = 0;
	virtual void Visit(ElementTwo& element) = 0;
};