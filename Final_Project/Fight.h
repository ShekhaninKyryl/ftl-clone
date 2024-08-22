#pragma once

class Ship;
class EnemyShip;


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

};