#include "Ship.h"

Ship::Ship(float x, float y) : 
    moving(false), 
    speed(100.f), 
    health(100), 
    damage(15), 
    maxShield(0), 
    shield(0),
    maneuverability(15),
    star(nullptr)
{
    texture = &Config::getInstance().textures["playerShip"];
    shipSprite.setTexture(*texture);

    auto tSize = texture->getSize();
    float scale = 64.f / tSize.x;

    shipSprite.setScale(scale, scale);
    shipSprite.setOrigin(tSize.x / 2, tSize.y / 2);
    shipSprite.setPosition(x, y);
}


void Ship::draw(sf::RenderWindow& window) {
    window.draw(shipSprite);
}

void Ship::moveTo(StarNode* targetStar, Map* map)
{
    if (getFuel() == 0) return;
   
    star->undockPlayer();
    star->setVisible(false);
    map->hideNodes(star->getId());
    star = targetStar;
    moving = true;

    resources.setFuel(getFuel() - 1);
}

void Ship::update(float deltaTime, Map* map) {
    if (moving) {
        sf::Vector2f currentPosition = shipSprite.getPosition();
        sf::Vector2f direction = star->getPosition() - currentPosition;
        double distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
       

        float angleRad = atan2(direction.y, direction.x);
        float angleDeg = angleRad * 180 / 3.14159265f;
        shipSprite.setRotation(angleDeg + 90);

        if (distance > 1.f) {
            direction /= static_cast<float>(distance);
            shipSprite.move(direction * speed * deltaTime);
        }
        else dockToStar(map);
    }
}

void Ship::takeDamage(int damage, std::string& log)
{
    health -= damage;
    if (health < 0) health = 0;
    std::cout << "Ship under atack: " << damage << " demage, health: " << health << std::endl;

    log = std::string("Ship under atack: " + std::to_string(damage) + " demage, health: " + std::to_string(health));
}

void Ship::dockToStar(Map* map)
{
    moving = false;
    star->dockPlayer(this);
    star->setVisible(true);
    star->setLockVisible();

    if (star) {
        shipSprite.setPosition(star->getPosition());
        map->higlightNodes(star->getId());
    }
}

void Ship::dockToStar(StarNode* node, Map* map)
{
    moving = false;
    node->dockPlayer(this);
    star = node;
    star->setVisible(true);
    star->setLockVisible();

    if (star) {
        shipSprite.setPosition(star->getPosition());
        map->higlightNodes(star->getId());
    }
}

void Ship::resize(float zoomFactor)
{
    shipSprite.setScale(shipSprite.getScale().x * zoomFactor, shipSprite.getScale().y * zoomFactor);
}

StarNode* Ship::getStar()
{
    return star;
}

sf::Vector2f Ship::getPosition() const {
    return shipSprite.getPosition();
}

int Ship::getHealth() const {
    return health;
}

int Ship::getDamage() const
{
    return damage;
}

int Ship::getManeuverability() const
{
    return maneuverability;
}

int Ship::getShield() const
{
    return shield;
}

int Ship::getMaxShield() const
{
    return maxShield;
}

int Ship::getFuel() const
{
    return resources.getFuel();
}

int Ship::getMoney() const
{
    return resources.getMoney();
}

void Ship::lootResources(const Resources& loot, std::string& log)
{
    std::cout << "You looted: " << loot.getFuel() << " fuel, and " << loot.getMoney() << " money!" << std::endl;
    resources += loot;

    log = std::string("You looted: " + std::to_string(loot.getFuel()) + " fuel, and " + std::to_string(loot.getMoney()) + " money!");
}
