#pragma once
#include "IElement.h"

class ElementOne : public IElement
{
public:
	virtual void Accept(IVisitor& visitor) override;
};

