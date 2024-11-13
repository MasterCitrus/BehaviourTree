#include "AttackBehaviour.h"
#include "Agent.h"

Status AttackBehaviour::Update(Agent* agent, float deltaTime)
{
	if (agent->GetTarget()->GetHP() <= 0) return Failure;

	agent->SetColour({ 255, 0, 0, 255 });
	timer -= deltaTime;

	if (timer <= 0.0f)
	{
		std::cout << "Attacking\n";
		timer = 0.5f;
		agent->GetTarget()->TakeDamage(agent->GetDamage());
		return Success;
	}
	return Failure;
}