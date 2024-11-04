#include "Composite.h"

Composite::~Composite()
{
	std::cout << "Composite destructor\n";
	for (auto& child : children) delete child;
}

void Composite::AddChild(Behaviour* behaviour)
{
	children.push_back(behaviour);
}
