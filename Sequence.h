#pragma once
#include "Composite.h"

class Sequence : public Composite
{
public:
	Status Update(Agent* agent, float deltaTime) override;
};

