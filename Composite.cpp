#include "Composite.h"

void Composite::AddChild(Behaviour* behaviour)
{
	children.push_back(behaviour);
}
