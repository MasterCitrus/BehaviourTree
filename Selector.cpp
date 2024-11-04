#include "Selector.h"

Status Selector::Update(Agent* agent, float deltaTime)
{
	auto current = children.begin();
	Behaviour* child = nullptr;

	if (!pending)
	{
		child = pending;
		pending = nullptr;
	}

	if (!child) child = *current;

	while (current != children.end())
	{
		Status status = child->Update(agent, deltaTime);

		if (status == Success) return Success;
		else if (status == Failure)
		{
			++current;
			if (current != children.end()) child = *current;
		}
		else if (status == Pending)
		{
			pending = child;
			return Pending;
		}
	}
	return Failure;
}
