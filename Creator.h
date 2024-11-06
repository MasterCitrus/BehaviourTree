#pragma once
#include "Behaviour.h"

class Creator
{
public:
	virtual ~Creator() {}
	Behaviour* CreateNode();

protected:
	virtual Behaviour* Create() = 0;
};

class SelectorCreator : public Creator
{
public:
	Behaviour* Create() override;
};

class SequenceCreator : public Creator
{
public:
	Behaviour* Create() override;
};

class InverterCreator : public Creator
{
	Behaviour* Create() override;
};

class AttackActionCreator : public Creator
{
public:
	Behaviour* Create() override;
};

class DeadActionCreator : public Creator
{
public:
	Behaviour* Create() override;
};

class FollowActionCreator : public Creator
{
public:
	Behaviour* Create() override;
};

class WanderActionCreator : public Creator
{
public:
	Behaviour* Create() override;
};

class ConditionCreator
{
public:
	virtual ~ConditionCreator() {}
	Behaviour* CreateCondition(float num, bool check);

protected:
	virtual Behaviour* Create(float num, bool check) = 0;
};

class DistanceConditionCreator : public ConditionCreator
{
public:
	Behaviour* Create(float num, bool check) override;
};

class HealthConditionCreator : public ConditionCreator
{
public:
	Behaviour* Create(float num, bool check) override;
};