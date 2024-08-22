#pragma once

#include <SFML/Graphics.hpp>

#include "UI_Base.h"
#include "Ship.h"

class UI_Player : public UI_Base
{
public:
	UI_Player(Ship* player);

	void initHealth();
	void updateHealth();
	void renderHealth(sf::RenderWindow& window);

	void initShield();
	void updateShield();
	void renderShield(sf::RenderWindow& window);

	void initDamage();
	void updateDamage();
	void renderDamage(sf::RenderWindow& window);

	void initMnvbility();
	void updateMnvbility();
	void renderMnvbility(sf::RenderWindow& window);


	void initResources();
	void updateResources();
	void renderResources(sf::RenderWindow& window);


	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	Ship* player;

	sf::Font font;

	sf::Text health;
	sf::RectangleShape healthBarOutline;
	sf::RectangleShape healthBarFill;

	sf::Text shield;
	sf::RectangleShape shieldBarOutline;
	sf::RectangleShape shieldBarFill;

	sf::Text damage;
	sf::Text maneuverability;


	sf::Text resources;
};