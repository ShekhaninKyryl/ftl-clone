#pragma once
#include <SFML/Graphics.hpp>
#include "StarNode.h"
#include "EnemyShip.h"

class StarNodeWithEnemy : public StarNode
{
public:
	StarNodeWithEnemy(float x, float y);
	void setVisible(bool visible) override;

	EnemyShip* enemy = nullptr;
};
