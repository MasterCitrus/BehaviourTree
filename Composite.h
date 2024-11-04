#pragma once
#include "Behaviour.h"
#include <vector>

class Composite : public Behaviour
{
public:
	virtual ~Composite();
	virtual Status Update(Agent* agent, float deltaTime) = 0;

	void AddChild(Behaviour* behaviour);
protected:
	std::vector<Behaviour*> children;
	Behaviour* pending = nullptr;
};

