#pragma once
#include "Composite.h"

class Selector : public Composite
{
public:
	void Update(Agent* agent, float deltaTime) override;
};

