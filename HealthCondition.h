#pragma once
#include "Condition.h"

class HealthCondition : public Condition
{
public:
	HealthCondition(float hp, bool isSelf) : hpLimit{ hp }, self{ isSelf } {}
	Status Update(Agent* agent, float deltaTime);
private:
	float hpLimit;
	bool self;
};

