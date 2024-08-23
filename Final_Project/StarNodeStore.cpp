#include "StarNodeStore.h"
#include "Config.h"
#include "Random.h"

StarNodeStore::StarNodeStore(float x, float y): StarNode(x, y)
{
	texture = &Config::getInstance().textures[randomBool() ? "nodeStore" : "nodeStore1"];
	nodeSprite.setTexture(*texture);

	auto tSize = texture->getSize();
	float scale = 64.f / tSize.x;

	nodeSprite.setScale(scale, scale);
	nodeSprite.setOrigin(tSize.x / 2, tSize.y / 2);
	nodeSprite.setPosition(x, y);
}

void StarNodeStore::setVisible(bool visible)
{
	if (lockVisible) return;

	isVisible = visible;
	if (visible) nodeSprite.setColor(sf::Color::White);
	else nodeSprite.setColor(sf::Color(64, 64, 64, 128));
}

void StarNodeStore::dockPlayer(Ship* player)
{
	this->player = player;
}
