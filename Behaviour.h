#pragma once
#include <iostream>

class Agent;

enum Status
{
	Success,
	Failure,
	Pending
};

class Behaviour
{
public:
	virtual ~Behaviour() { std::cout << "Behaviour destructor\n"; }
	virtual Status Update(Agent* agent, float deltaTime) = 0;
	virtual void AddChild(Behaviour* behaviour) {}
};

