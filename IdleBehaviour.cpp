#include "IdleBehaviour.h"
#include "Agent.h"

Status IdleBehaviour::Update(Agent* agent, float deltaTime)
{
	if (!agent->PathComplete())
	{
		agent->Reset();
		return Success;
	}
	return Failure;
}
