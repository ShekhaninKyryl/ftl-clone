#include "StarNodeWithEnemy.h"
#include "EnemyShip.h"

StarNodeWithEnemy::StarNodeWithEnemy(float x, float y) : StarNode(x, y)
{
}

void StarNodeWithEnemy::setVisible(bool visible)
{
	if (lockVisible) return;

	isVisible = visible;
	if (visible) nodeShape.setFillColor(sf::Color::Yellow);
	else nodeShape.setFillColor(sf::Color(64, 64, 64));
}

void StarNodeWithEnemy::dockPlayer(Ship* player)
{
	this->player = player;

	auto position = nodeShape.getPosition();
	this->enemy = new EnemyShip(position.x, position.y);
}
