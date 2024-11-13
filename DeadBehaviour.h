#pragma once
#include "Behaviour.h"

class DeadBehaviour : public Behaviour
{
public:
	virtual Status Update(Agent* agent, float deltaTime) override;

	int check = 0;
};

