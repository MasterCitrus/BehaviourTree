#include "Sequence.h"

void Sequence::Update(Agent* agent, float deltaTime)
{
	for (auto& child : children)
	{
		if (child->Update(agent, deltaTime))
	}
}
