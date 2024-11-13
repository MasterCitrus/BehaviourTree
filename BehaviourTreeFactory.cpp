#include "BehaviourTreeFactory.h"
#include "Creator.h"
#include "NodeMap.h"

Behaviour* BehaviourTreeFactory::Create(INavigatable* map)
{
	//Create Root Node
	Creator* nodeCreator = new SelectorCreator();
	Behaviour* root = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	//Dead Behaviour
	//Creation of Behaviour Root Node
	nodeCreator = new SequenceCreator();
	Behaviour* child = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	//Children of Behaviour
	ConditionCreator* conditionCreator = new HealthConditionCreator();
	Behaviour* condition = conditionCreator->CreateCondition(0.0f, true);
	child->AddChild(condition);
	delete conditionCreator;
	conditionCreator = nullptr;

	nodeCreator = new DeadActionCreator();
	Behaviour* action = nodeCreator->CreateNode();
	child->AddChild(action);
	delete nodeCreator;
	nodeCreator = nullptr;

	root->AddChild(child);

	//Attack Behaviour
	//Creation of Behaviour Root Node
	nodeCreator = new SequenceCreator();
	child = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	//Children of Behaviour
	conditionCreator = new HealthConditionCreator();
	condition = conditionCreator->CreateCondition(0.0f, false);
	delete conditionCreator;
	conditionCreator = nullptr;

	nodeCreator = new InverterCreator();
	Behaviour* child2 = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	child2->AddChild(condition);
	child->AddChild(child2);

	conditionCreator = new DistanceConditionCreator();
	condition = conditionCreator->CreateCondition(1.0f * map->GetCellSize(), true);
	child->AddChild(condition);
	delete conditionCreator;
	conditionCreator = nullptr;

	nodeCreator = new AttackActionCreator();
	action = nodeCreator->CreateNode();
	child->AddChild(action);
	delete nodeCreator;
	nodeCreator = nullptr;

	root->AddChild(child);

	//Follow Behaviour
	//Creation of Behaviour Root Node
	nodeCreator = new SequenceCreator();
	child = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	//Children of Behaviour
	nodeCreator = new InverterCreator();
	child2 = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	conditionCreator = new HealthConditionCreator();
	condition = conditionCreator->CreateCondition(0.0f, false);
	delete conditionCreator;
	conditionCreator = nullptr;

	child2->AddChild(condition);
	child->AddChild(child2);

	conditionCreator = new DistanceConditionCreator();
	condition = conditionCreator->CreateCondition(1.0f * map->GetCellSize(), false);
	child->AddChild(condition);

	condition = conditionCreator->CreateCondition(2.5f * map->GetCellSize(), true);
	child->AddChild(condition);

	nodeCreator = new FollowActionCreator();
	action = nodeCreator->CreateNode();
	child->AddChild(action);
	delete nodeCreator;
	nodeCreator = nullptr;

	root->AddChild(child);

	//Wander Behaviour
	//Creation of Behaviour Root Node
	nodeCreator = new SequenceCreator();
	child = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	//Children of Behaviour
	nodeCreator = new SelectorCreator();
	child2 = nodeCreator->CreateNode();
	delete nodeCreator;
	nodeCreator = nullptr;

	condition = conditionCreator->CreateCondition(4.0f * map->GetCellSize(), false);
	delete conditionCreator;
	conditionCreator = nullptr;
	child2->AddChild(condition);

	conditionCreator = new HealthConditionCreator();
	condition = conditionCreator->CreateCondition(0.0f, false);
	child2->AddChild(condition);
	child->AddChild(child2);


	nodeCreator = new WanderActionCreator();
	action = nodeCreator->CreateNode();
	child->AddChild(action);

	root->AddChild(child);

	delete nodeCreator;
	delete conditionCreator;

	return root;
}
