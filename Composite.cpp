#include "Composite.h"

Composite::~Composite()
{
	std::cout << "Composite destructor\n";
	int i = 0;
	for (auto& child : children)
	{
		delete child;
		std::cout << "Child " << i << " deleted.\n";
		i++;
	}
}

void Composite::AddChild(Behaviour* behaviour)
{
	children.push_back(behaviour);
}
