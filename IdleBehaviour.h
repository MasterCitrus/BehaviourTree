#pragma once
#include "Behaviour.h"

class IdleBehaviour : public Behaviour
{
public:
	virtual Status Update(Agent* agent, float deltaTime) override;
private:
	float timer = 2.0f;
};

