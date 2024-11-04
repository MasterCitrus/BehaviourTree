#include "WanderBehaviour.h"
#include "Agent.h"

Status WanderBehaviour::Update(Agent* agent, float deltaTime)
{
	agent->SetColour({ 0, 255, 255, 255 });
	if (agent->PathComplete())
	{
		agent->GoTo(agent->GetNodeMap()->GetRandomNode()->position);
		return Success;
	}
	else return Failure;
}
