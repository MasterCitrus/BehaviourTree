#include "Creator.h"
#include "Selector.h"
#include "Sequence.h"
#include "Inverter.h"
#include "AttackBehaviour.h"
#include "DeadBehaviour.h"
#include "FollowBehaviour.h"
#include "WanderBehaviour.h"
#include "DistanceCondition.h"
#include "HealthCondition.h"

Behaviour* Creator::CreateNode()
{
	Behaviour* node = this->Create();
	return node;
}

Behaviour* SelectorCreator::Create()
{
	return new Selector();
}

Behaviour* SequenceCreator::Create()
{
	return new Sequence();
}

Behaviour* AttackActionCreator::Create()
{
	return new AttackBehaviour();
}

Behaviour* DeadActionCreator::Create()
{
	return new DeadBehaviour();
}

Behaviour* FollowActionCreator::Create()
{
	return new FollowBehaviour();
}

Behaviour* WanderActionCreator::Create()
{
	return new WanderBehaviour();
}

Behaviour* ConditionCreator::CreateCondition(float num, bool check)
{
	Behaviour* condition = this->Create(num, check);
	return condition;
}

Behaviour* DistanceConditionCreator::Create(float num, bool check)
{
	return new DistanceCondition(num, check);
}

Behaviour* HealthConditionCreator::Create(float num, bool check)
{
	return new HealthCondition(num, check);
}

Behaviour* InverterCreator::Create()
{
	return new Inverter();
}
