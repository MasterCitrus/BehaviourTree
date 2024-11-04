#pragma once
#include "Composite.h"

class Selector : public Composite
{
public:
	Status Update(Agent* agent, float deltaTime) override;
};

