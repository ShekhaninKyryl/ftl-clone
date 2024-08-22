#include "UI_Player.h"

UI_Player::UI_Player(Ship* player)
{
	this->player = player;
    font = FontManager::getInstance().fonts["font1"];

    initHealth();
    initShield();
    initDamage();
    initMnvbility();
    initResources();
}

void UI_Player::initHealth()
{
    health.setFont(font);
    health.setCharacterSize(18);
    health.setFillColor(sf::Color::White);
    health.setPosition(10.f, 10.f);

    healthBarOutline.setSize(sf::Vector2f(200.f, 18.f));
    healthBarOutline.setFillColor(sf::Color::Transparent);
    healthBarOutline.setOutlineThickness(2.f);
    healthBarOutline.setOutlineColor(sf::Color::White);
    healthBarOutline.setPosition(120.f, 10.f);


    healthBarFill.setSize(sf::Vector2f(200.f, 18.f));
    healthBarFill.setFillColor(sf::Color::Red);
    healthBarFill.setPosition(120.f, 10.f);
}

void UI_Player::updateHealth()
{
    health.setString("Health: " + std::to_string(player->getHealth()));

    float  healthPercentage = player->getHealth() / 100.f;

    if (healthPercentage > 1.f) healthPercentage = 1.f;

    healthBarFill.setSize(sf::Vector2f(200.f * healthPercentage, 18.f));
}

void UI_Player::renderHealth(sf::RenderWindow& window)
{
    window.draw(healthBarOutline);
    window.draw(healthBarFill);
    window.draw(health);
}

void UI_Player::initShield()
{
    shield.setFont(font);
    shield.setCharacterSize(18);
    shield.setFillColor(sf::Color::White);
    shield.setPosition(10.f, 40.f);

    shieldBarOutline.setSize(sf::Vector2f(200.f, 18.f));
    shieldBarOutline.setFillColor(sf::Color::Transparent);
    shieldBarOutline.setOutlineThickness(2.f);
    shieldBarOutline.setOutlineColor(sf::Color::Blue);
    shieldBarOutline.setPosition(120.f, 40.f);


    shieldBarFill.setSize(sf::Vector2f(200.f, 18.f));
    shieldBarFill.setFillColor(sf::Color::Blue);
    shieldBarFill.setPosition(120.f, 40.f);
}

void UI_Player::updateShield()
{
    shield.setString("Shield: " + std::to_string(player->getShield()));

    float  shieldPercentage = player->getMaxShield() == 0 ? 0 : player->getShield() / player->getMaxShield();

    if (shieldPercentage > 1.f) shieldPercentage = 1.f;

    shieldBarFill.setSize(sf::Vector2f(200.f * shieldPercentage, 18.f));
}

void UI_Player::renderShield(sf::RenderWindow& window)
{
    window.draw(shieldBarOutline);
    window.draw(shieldBarFill);
    window.draw(shield);
}

void UI_Player::initDamage()
{
    damage.setFont(font);
    damage.setCharacterSize(18);
    damage.setFillColor(sf::Color::White);
    damage.setPosition(10.f, 70.f);
}

void UI_Player::updateDamage()
{
    damage.setString("Damage: " + std::to_string(player->getDamage()));
}

void UI_Player::renderDamage(sf::RenderWindow& window)
{
    window.draw(damage);
}

void UI_Player::initMnvbility()
{
    maneuverability.setFont(font);
    maneuverability.setCharacterSize(18);
    maneuverability.setFillColor(sf::Color::White);
    maneuverability.setPosition(10.f, 100.f);
}

void UI_Player::updateMnvbility()
{
    maneuverability.setString("Maneuverability: " + std::to_string(player->getManeuverability()) + "%");
}

void UI_Player::renderMnvbility(sf::RenderWindow& window)
{
    window.draw(maneuverability);
}

void UI_Player::initResources()
{
    resources.setFont(font);
    resources.setCharacterSize(18);
    resources.setFillColor(sf::Color::White);
    //maneuverability.setPosition(10.f, 100.f);
}

void UI_Player::updateResources()
{
    if(player->getFuel() == 0)
      resources.setString("Fuel: 0 - can't move\tMoney: " + std::to_string(player->getMoney()));
    else
      resources.setString("Fuel: " + std::to_string(player->getFuel()) + "\tMoney: " + std::to_string(player->getMoney()));
}

void UI_Player::renderResources(sf::RenderWindow& window)
{
    auto windowSize = window.getSize();
    resources.setPosition(10.f, windowSize.y - 30);
    window.draw(resources);
}

void UI_Player::update()
{
    updateHealth();
    updateShield();
    updateDamage();
    updateMnvbility();
    updateResources();
}

void UI_Player::render(sf::RenderWindow& window)
{
    renderHealth(window);
    renderShield(window);
    renderDamage(window);
    renderMnvbility(window);
    renderResources(window);
}
