#pragma once
#include "Composite.h"

class Sequence : public Composite
{
public:
	void Update(Agent* agent, float deltaTime) override;
};

