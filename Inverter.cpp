#include "Inverter.h"

Status Inverter::Update(Agent* agent, float deltaTime)
{
    Status status = child->Update(agent, deltaTime);

    if (status == Success) return Failure;
    else if (status == Failure) return Success;
}

void Inverter::AddChild(Behaviour* child)
{
    this->child = child;
}
