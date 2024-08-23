#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <algorithm>

#include "Ship.h"
#include "EnemyShip.h"
#include "Map.h"
#include "Fight.h"
#include "UI.h"

enum class GameState {
	Map,
	Battle
};

class Game {
public: 
	Game(sf::RenderWindow& window);
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void updateView(sf::RenderWindow& window, const sf::Vector2f& playerPosition);

	sf::RenderWindow& window;
	sf::View view;
	GameState currentState;

	Ship playerShip;

	Fight* fight;
	Map* map;
	UI* gameUI;

	sf::Texture* backgroundTexture;
	sf::Sprite backgroundSprite;
};