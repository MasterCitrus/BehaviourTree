#pragma once
#include "Behaviour.h"
#include "glm/vec2.hpp"

class FollowBehaviour : public Behaviour
{
public:
	virtual Status Update(Agent* agent, float deltaTime) override;

private:
	glm::vec2 lastTargetPosition = { 0, 0 };
};

