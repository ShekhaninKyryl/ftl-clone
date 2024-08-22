#include "StarNodeWithEnemy.h"

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
