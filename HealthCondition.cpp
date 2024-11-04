#include "HealthCondition.h"
#include "Agent.h"

Status HealthCondition::Update(Agent* agent, float deltaTime)
{
    if (!self)
    {
        if (agent->GetTarget()->GetHP() <= hpLimit) return Success;
    }
    else
    {
        if (agent->GetHP() <= hpLimit) return Success;
    }
    return Failure;
}
