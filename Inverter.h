#pragma once
#include "behaviour.h"

class Inverter : public Behaviour
{
public:
	Status Update(Agent* agent, float deltaTime);

	void AddChild(Behaviour* child) override;

private:
	Behaviour* child;
};

