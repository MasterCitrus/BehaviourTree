#include "BehaviourTreeFactory.h"
#include "Creator.h"
#include "NodeMap.h"

Behaviour* BehaviourTreeFactory::Create(INavigatable* map)
{
	//Create Root Node
	Creator* nodeCreator = new SelectorCreator();
	Behaviour* root = nodeCreator->CreateNode();

	//Dead Behaviour
	//Creation of first branch
	nodeCreator = new SequenceCreator();
	Behaviour* child = nodeCreator->CreateNode();

	//Children of first branch
	ConditionCreator* conditionCreator = new HealthConditionCreator();
	Behaviour* condition = conditionCreator->CreateCondition(0.0f, true);
	child->AddChild(condition);

	nodeCreator = new DeadActionCreator();
	Behaviour* action = nodeCreator->CreateNode();
	child->AddChild(action);

	root->AddChild(child);

	//Attack Behaviour
	//Creation of second branch
	nodeCreator = new SequenceCreator();
	child = nodeCreator->CreateNode();

	//Children of second branch
	conditionCreator = new DistanceConditionCreator();
	condition = conditionCreator->CreateCondition(1.0f * map->GetCellSize(), true);
	child->AddChild(condition);

	conditionCreator = new HealthConditionCreator();
	condition = conditionCreator->CreateCondition(0.0f, false);

	nodeCreator = new InverterCreator();
	Behaviour* child2 = nodeCreator->CreateNode();
	
	child2->AddChild(condition);
	child->AddChild(child2);

	nodeCreator = new AttackActionCreator();
	action = nodeCreator->CreateNode();
	child->AddChild(action);

	root->AddChild(child);

	//Follow Behaviour
	//Creation of third branch
	nodeCreator = new SequenceCreator();
	child = nodeCreator->CreateNode();

	//Children of third branch
	condition = conditionCreator->CreateCondition(1.0f * map->GetCellSize(), false);
	child->AddChild(condition);

	condition = conditionCreator->CreateCondition(2.5f * map->GetCellSize(), true);
	child->AddChild(condition);

	nodeCreator = new FollowActionCreator();
	action = nodeCreator->CreateNode();
	child->AddChild(action);

	root->AddChild(child);

	//Wander Behaviour
	//Creation of fourth branch
	nodeCreator = new SequenceCreator();
	child = nodeCreator->CreateNode();

	//Children of fourth branch
	condition = conditionCreator->CreateCondition(4.0f * map->GetCellSize(), false);
	child->AddChild(condition);

	nodeCreator = new WanderActionCreator();
	action = nodeCreator->CreateNode();
	child->AddChild(action);

	root->AddChild(child);

	delete nodeCreator;
	delete conditionCreator;

	return root;
}
