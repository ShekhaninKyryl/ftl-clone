#include "StarNodeShadow.h"
#include "EnemyShip.h"

StarNodeShadow::StarNodeShadow(float x, float y) : StarNode(x, y)
{
}

void StarNodeShadow::setVisible(bool visible)
{
	if (lockVisible) return;

	isVisible = visible;
	if(visible) nodeShape.setFillColor(sf::Color::Cyan);
	else nodeShape.setFillColor(sf::Color(64, 64, 64));
}

void StarNodeShadow::dockPlayer(Ship* player)
{
	this->player = player;

	auto position = nodeShape.getPosition();
	this->enemy = new EnemyShip(position.x, position.y);
}
