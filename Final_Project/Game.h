#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <algorithm>
#include <random>

#include "Ship.h"
#include "EnemyShip.h"
#include "Map.h"
#include "UI.h"

#include "Random.h"




class Game {
public: 
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void updateView(sf::RenderWindow& window, const sf::Vector2f& playerPosition);

	sf::RenderWindow window;
	sf::View view;

	Ship playerShip;

	Map* map;
	UI* gameUI;
};