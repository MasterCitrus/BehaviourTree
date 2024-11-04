#pragma once
#include "Behaviour.h"

class Agent;

class Condition : public Behaviour
{
public:
	virtual ~Condition() { std::cout << "Condition destructor\n"; }
	virtual Status Update(Agent* agent, float deltaTime) = 0;
};