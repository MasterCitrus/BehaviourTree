#include "GotoBehaviour.h"
#include "raylib.h"
#include "glm/vec2.hpp"
#include "Agent.h"

Status GotoBehaviour::Update(Agent* agent, float deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		agent->GoTo(glm::vec2(mousePos.x, mousePos.y));
		return Success;
	}
	return Failure;
}
