#include "FollowBehaviour.h"
#include "Agent.h"

Status FollowBehaviour::Update(Agent* agent, float deltaTime)
{
	agent->SetColour({ 255, 127, 0, 255 });

	Agent* target = agent->GetTarget();
	float distance = glm::distance(target->GetPosition(), lastTargetPosition);

	if (distance > agent->GetNodeMap()->GetCellSize())
	{
		std::cout << "Following\n";
		agent->Reset();
		lastTargetPosition = target->GetPosition();
		agent->GoTo(lastTargetPosition);
		return Success;
	}
	else return Failure;
}