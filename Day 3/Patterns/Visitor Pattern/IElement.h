#pragma once

class IVisitor;

class IElement
{
public:
	virtual ~IElement() {}
	virtual void Accept(IVisitor& visitor) = 0;
};
