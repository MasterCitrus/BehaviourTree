#pragma once
#include "Behaviour.h"

class WanderBehaviour : public Behaviour
{
public:
	virtual Status Update(Agent* agent, float deltaTime) override;
};

