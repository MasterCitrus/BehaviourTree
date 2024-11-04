#include "Sequence.h"

Status Sequence::Update(Agent* agent, float deltaTime)
{
	auto current = children.begin();
	Behaviour* child = nullptr;

	if (pending != nullptr)
	{
		child = pending;
		pending = nullptr;
	}

	if (child == nullptr) child = *current;
	
	while (current != children.end())
	{
		Status status = child->Update(agent, deltaTime);

		if (status == Failure) return Failure;
		else if (status == Success)
		{
			++current;
			if(current != children.end()) child = *current;
		}
		else if (status == Pending)
		{
			pending = child;
			return Pending;
		}
	}
	return Success;
}
