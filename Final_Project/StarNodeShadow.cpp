#include "StarNodeShadow.h"

StarNodeShadow::StarNodeShadow(float x, float y) : StarNodeWithEnemy(x, y)
{
}

void StarNodeShadow::setVisible(bool visible)
{
	if (lockVisible) return;

	isVisible = visible;
	if(visible) nodeShape.setFillColor(sf::Color::Cyan);
	else nodeShape.setFillColor(sf::Color(64, 64, 64));
}
