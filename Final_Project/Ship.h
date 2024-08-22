#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class StarNode;
class Map;
class Resources;

class Ship
{
public:
	Ship() : Ship(0.f, 0.f) {}
	Ship(float x, float y);

	void draw(sf::RenderWindow& window);
	void moveTo(StarNode* targetStar, Map* map);
	void update(float deltaTime, Map* map);
	void takeDamage(int damage);
	void dockToStar(Map* map);
	void dockToStar(StarNode* node, Map* map);
	void resize(float zoomFactor);
	StarNode* getStar();

	sf::Vector2f getPosition() const;
	int getHealth() const;
	int getDamage() const;
	int getManeuverability() const;

	int getShield() const;
	int getMaxShield() const;

	int getFuel() const;
	int getMoney() const;

private:
	sf::RectangleShape shipShape;
	StarNode* star;
	Resources resources;

	bool moving;
	float speed;
	// from 0 to 100+
	int health;

	// from 1 to 100+
	int damage;

	// from 0 to 100+
	int shield;
	int maxShield;

	// from 0 to 100 %
	int maneuverability;
};