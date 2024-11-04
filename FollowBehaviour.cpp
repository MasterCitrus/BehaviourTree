#include "FollowBehaviour.h"
#include "Agent.h"

Status FollowBehaviour::Update(Agent* agent, float deltaTime)
{
	Agent* target = agent->GetTarget();

	float distance = glm::distance(target->GetPosition(), lastTargetPosition);

	if (distance > agent->GetNodeMap()->GetCellSize())
	{
		agent->Reset();
		agent->SetColour({ 255, 127, 0, 255 });
		lastTargetPosition = target->GetPosition();
		agent->GoTo(lastTargetPosition);
		return Success;
	}
	else return Failure;
}