#pragma once
#include "INavigatable.h"

class Behaviour;

class BehaviourTreeFactory
{
public:
	Behaviour* Create(INavigatable* map);
};

