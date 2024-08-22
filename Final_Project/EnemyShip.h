#pragma once

#include <SFML/Graphics.hpp>


class EnemyShip
{
public:
	EnemyShip(float x, float y);    
    void draw(sf::RenderWindow& window) const;
    void update(float deltaTime);
    void takeDamage(int damage);

    sf::Vector2f getPosition() const;
    int getHealth() const;
    int getDamage() const;


private:
    sf::RectangleShape enemyShape;
    int health;  // Здоров'я ворога
    int damage;  // Сила ворога

};