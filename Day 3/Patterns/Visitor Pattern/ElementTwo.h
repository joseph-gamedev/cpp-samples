#pragma once
#include "IElement.h"

class ElementTwo :public IElement
{
public:
	virtual void Accept(IVisitor& visitor) override;
};

