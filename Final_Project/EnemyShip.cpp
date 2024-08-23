#include "EnemyShip.h"


EnemyShip::EnemyShip(float x, float y) : health(50), damage(10), maxLoot(3, 30) {
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

void EnemyShip::takeDamage(int damage, std::string& log) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << "Enemy under atack: " << damage << ", health: " << health << std::endl;

    log = std::string("Enemy under atack: " + std::to_string(damage) + " demage, health: " + std::to_string(health));
}

Resources EnemyShip::grabLoot()
{
    randomFloat(0.8f, 1.f);
    auto loot = maxLoot;
    loot.setFuel(loot.getFuel() * randomFloat(0.8f, 1.f));
    loot.setMoney(loot.getMoney() * randomFloat(0.8f, 1.f));
    return loot;
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
