#include "DeadBehaviour.h"
#include "Agent.h"

Status DeadBehaviour::Update(Agent* agent, float deltaTime)
{
	if (agent->GetHP() <= 0.0f)
	{
		agent->Reset();
		agent->SetColour({ 127, 127, 127, 255 });
		return Success;
	}
	else return Failure;
}
