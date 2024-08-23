#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Resources.h"
#include "Random.h"


class EnemyShip
{
public:
	EnemyShip(float x, float y);    
    void draw(sf::RenderWindow& window) const;
    void update(float deltaTime);
    void takeDamage(int damage, std::string& log);
    Resources grabLoot();

    sf::Vector2f getPosition() const;
    int getHealth() const;
    int getDamage() const;


private:
    sf::RectangleShape enemyShape;
    Resources maxLoot;
    int health;  // Здоров'я ворога
    int damage;  // Сила ворога

};