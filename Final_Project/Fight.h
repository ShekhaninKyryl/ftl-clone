#pragma once

#include <iostream>
#include <vector>

#include "Ship.h"
#include "EnemyShip.h"


enum class FightState
{
	Idle,
	Win,
	Lose,
};

class Fight
{
public:
	Fight(Ship* player, EnemyShip* enemy);

	FightState update(float deltaTime);

private:
	Ship* player;
	EnemyShip* enemy;
	std::vector<std::string> logs;

};