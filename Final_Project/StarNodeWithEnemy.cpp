#include "StarNodeWithEnemy.h"
#include "EnemyShip.h"
#include "Config.h"

StarNodeWithEnemy::StarNodeWithEnemy(float x, float y) : StarNode(x, y)
{
	texture = &Config::getInstance().textures["nodeWithEnemy"];
	nodeSprite.setTexture(*texture);

	auto tSize = texture->getSize();
	float scale = 64.f / tSize.x;

	nodeSprite.setScale(scale, scale);
	nodeSprite.setOrigin(tSize.x / 2, tSize.y / 2);
	nodeSprite.setPosition(x, y);
}

void StarNodeWithEnemy::setVisible(bool visible)
{
	if (lockVisible) return;

	isVisible = visible;
	if (visible) nodeSprite.setColor(sf::Color::White);
	else nodeSprite.setColor(sf::Color(64, 64, 64, 128));
}

void StarNodeWithEnemy::dockPlayer(Ship* player)
{
	this->player = player;

	auto position = nodeSprite.getPosition();
	this->enemy = new EnemyShip(position.x, position.y);
}
