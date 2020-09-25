#include "ElementTwo.h"
#include "IVisitor.h"

void ElementTwo::Accept(IVisitor & visitor)
{
	visitor.Visit(*this);
}
