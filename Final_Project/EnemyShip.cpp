#include <iostream>
#include "EnemyShip.h"

EnemyShip::EnemyShip(float x, float y) : health(50), damage(10) {
    enemyShape.setSize(sf::Vector2f(30.f, 15.f));
    enemyShape.setFillColor(sf::Color::Red);
    enemyShape.setPosition(x, y);
}

void EnemyShip::draw(sf::RenderWindow& window) const {
    window.draw(enemyShape);
}

void EnemyShip::update(float deltaTime) {
    // Додамо пізніше поведінку ворожого корабля
}

void EnemyShip::takeDamage(int damage) {
    health -= damage;
    std::cout << "Enemy under atack: " << damage << ", health: " << health << std::endl;
}

sf::Vector2f EnemyShip::getPosition() const {
    return enemyShape.getPosition();
}

int EnemyShip::getHealth() const {
    return health;
}

int EnemyShip::getDamage() const
{
    return damage;
}
