#include "StarNodeStore.h"

StarNodeStore::StarNodeStore(float x, float y): StarNode(x, y)
{

}

void StarNodeStore::setVisible(bool visible)
{
	if (lockVisible) return;

	isVisible = visible;
	if (visible) nodeShape.setFillColor(sf::Color::Magenta);
	else nodeShape.setFillColor(sf::Color(64, 64, 64));
}

void StarNodeStore::dockPlayer(Ship* player)
{
	this->player = player;
}
