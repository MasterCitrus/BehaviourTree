#pragma once
#include "Behaviour.h"
class AttackBehaviour : public Behaviour
{
public:
	virtual Status Update(Agent* agent, float deltaTime) override;
private:
	float timer = 0.5f;
};

