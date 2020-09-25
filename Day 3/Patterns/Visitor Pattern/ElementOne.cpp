#include "ElementOne.h"
#include "IVisitor.h"

void ElementOne::Accept(IVisitor & visitor)
{
	visitor.Visit(*this);
}
