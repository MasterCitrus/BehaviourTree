#include "raylib.h"
#include "NodeMap.h"
#include "Agent.h"
#include "BehaviourTreeFactory.h"
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <random>
#include <iostream>


int main()
{
	{
		int screenWidth = 1280;
		int screenHeight = 720;

		int num = 1;
		std::string number;

		//Random settings
		srand(time(nullptr));
		std::random_device rd;
		std::mt19937 gen(rd());

		//MAP LOADING
		std::vector<std::string> mapFileNames;

		const std::filesystem::path maps{ "maps" };

		for (auto const& dir_entry : std::filesystem::directory_iterator{ maps })
		{
			mapFileNames.push_back(dir_entry.path().filename().string());
		}

		std::uniform_int_distribution<> randomMapNumber(0, mapFileNames.size() - 1);

		std::ifstream mapFile("maps/" + *(mapFileNames.begin() + randomMapNumber(gen)));

		std::vector<std::string> asciiMap;

		for (std::string line; std::getline(mapFile, line);)
		{
			asciiMap.push_back(line);
		}

		int emptyLines = 0;
		for (auto& string : asciiMap)
		{
			if (string.find('1') != string.npos) break;
			else emptyLines++;
		}

		if (emptyLines == asciiMap.size())
		{
			std::cout << "\n---{{{Invalid Map - No valid nodes}}}---\n";
			return 1;
		}
		//MAP LOADING END

		bool drawPaths = false;

		InitWindow(screenWidth, screenHeight, "Pathfinding");
		SetTargetFPS(60);

		//NodeMap setup
		NodeMap map;
		map.Intialise(asciiMap, 50);

		std::cout << "\nPress 'Space' to show path lines.\n";

		Node* start = map.GetNode(1, 1);

		//Conditions
		//DistanceCondition* closerThan2Half = new DistanceCondition(2.5f * map.GetCellSize(), true);
		//DistanceCondition* furtherThan4 = new DistanceCondition(4.0f * map.GetCellSize(), false);
		//DistanceCondition* closerThanOne = new DistanceCondition(1.0f * map.GetCellSize(), true);
		//DistanceCondition* furtherThanOne = new DistanceCondition(1.0f * map.GetCellSize(), false);
		//HealthCondition* targetDead = new HealthCondition(0.0f, false);
		//HealthCondition* dead = new HealthCondition(0.0f, true);

		//Behaviour Tree Setup
		BehaviourTreeFactory factory;

		Behaviour* AITree1 = factory.Create(&map);
		Behaviour* AITree2 = factory.Create(&map);
		Behaviour* AITree3 = factory.Create(&map);
		Behaviour* AITree4 = factory.Create(&map);

		//Agent setup

		//Player
		//Agent agent(&map, playerFSM);
		//agent.GetPathAgent().SetNode(start);
		//agent.GetPathAgent().SetSpeed(128);
		//agent.SetDamage(25);

		//AI Agents
		Agent agent2(&map, AITree1);
		agent2.GetPathAgent().SetNode(map.GetRandomNode());
		agent2.GetPathAgent().SetSpeed(64);
		agent2.SetDamage(10);

		Agent agent3(&map, AITree2);
		agent3.GetPathAgent().SetNode(map.GetRandomNode());
		agent3.GetPathAgent().SetSpeed(64);
		agent3.SetDamage(10);

		Agent agent4(&map, AITree3);
		agent4.GetPathAgent().SetNode(map.GetRandomNode());
		agent4.GetPathAgent().SetSpeed(64);
		agent4.SetDamage(10);

		Agent agent5(&map, AITree4);
		agent5.GetPathAgent().SetNode(map.GetRandomNode());
		agent5.GetPathAgent().SetSpeed(64);
		agent5.SetDamage(10);

		agent2.SetTarget(&agent3);
		agent3.SetTarget(&agent4);
		agent4.SetTarget(&agent5);
		agent5.SetTarget(&agent2);

		std::vector<Agent*> agents;

		//agents.push_back(&agent);
		agents.push_back(&agent2);
		agents.push_back(&agent3);
		agents.push_back(&agent4);
		agents.push_back(&agent5);

		Color lineColour = { 255, 255, 255, 255 };

		while (!WindowShouldClose())
		{
			float deltaTime = GetFrameTime();

			BeginDrawing();

			ClearBackground(GRAY);

			map.Draw();


			if (IsKeyPressed(KEY_SPACE)) drawPaths = !drawPaths;

			for (auto& a : agents)
			{
				number = std::to_string(num);
				a->Update(deltaTime);
				a->Draw();
				DrawText(number.c_str(), a->GetPosition().x, a->GetPosition().y, 5, BLACK);
				num++;
			}

			num = 1;

			//Draw all connections
			if (drawPaths)
			{
				//map.DrawPath(&agent, agent.GetColor());
				map.DrawPath(&agent2, agent2.GetColor());
				map.DrawPath(&agent3, agent3.GetColor());
				map.DrawPath(&agent4, agent4.GetColor());
				map.DrawPath(&agent5, agent5.GetColor());
			}

			//std::string text = "HP: " + std::to_string(agent.GetHP());
			//DrawText(text.c_str(), 10, 10, 20, WHITE);

			//if (agent.GetHP() <= 0) DrawText("YOU DEAD MON?", (screenWidth / 2) - 450, (screenHeight / 2) - 75, 100, BLACK);

			EndDrawing();
		}

		delete AITree1;
		delete AITree2;
		delete AITree3;
		delete AITree4;

		CloseWindow();
	}
}