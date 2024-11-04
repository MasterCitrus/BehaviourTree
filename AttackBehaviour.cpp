#include "AttackBehaviour.h"
#include "Agent.h"

Status AttackBehaviour::Update(Agent* agent, float deltaTime)
{
	timer -= deltaTime;

	if (timer <= 0.0f)
	{
		agent->SetColour({ 255, 0, 0, 255 });
		timer = 0.5f;
		agent->GetTarget()->TakeDamage(agent->GetDamage());
		return Success;
	}
	return Failure;
}