#include "DistanceCondition.h"
#include "glm/glm.hpp"
#include "Agent.h"

Status DistanceCondition::Update(Agent* agent, float deltaTime)
{
    bool result = glm::distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < m_distance;
    if ( result == m_lessThan) return Success;
    else return Failure;
}
