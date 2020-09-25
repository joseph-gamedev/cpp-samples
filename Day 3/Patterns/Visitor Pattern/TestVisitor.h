#pragma once
#include "IVisitor.h"

class ElementOne;
class ElementTwo;

class TestVisitor :public IVisitor
{
public:
	virtual void Visit(ElementOne& element) override;
	virtual void Visit(ElementTwo& element) override;
};

