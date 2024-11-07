#pragma once
#include "behaviour.h"

class Inverter : public Behaviour
{
public:
	~Inverter();
	Status Update(Agent* agent, float deltaTime);

	void AddChild(Behaviour* child) override;

private:
	Behaviour* child = nullptr;
};

