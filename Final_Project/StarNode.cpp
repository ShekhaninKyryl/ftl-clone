#include <string>
#include "StarNode.h"
#include "Config.h"


StarNode::StarNode(float x, float y) : id(nextId++) {
    texture = &Config::getInstance().textures["node"];
    nodeSprite.setTexture(*texture);

    auto tSize = texture->getSize();
    float scale = 64.f / tSize.x;

    nodeSprite.setScale(scale, scale);
    nodeSprite.setOrigin(tSize.x / 2, tSize.y / 2);
    nodeSprite.setPosition(x, y);
}

void StarNode::draw(sf::RenderWindow& window) const {
    window.draw(nodeSprite);
}

sf::Vector2f StarNode::getPosition() const {
    return nodeSprite.getPosition();
}

unsigned StarNode::getId() const
{
    return id;
}

unsigned StarNode::getLastId()
{
    return nextId;
}

void StarNode::undockPlayer()
{
    player = nullptr;
}

void StarNode::dockPlayer(Ship* player)
{
    this->player = player;
}

void StarNode::setVisible(bool visible)
{
    if (lockVisible) return;
    isVisible = visible;
    if (visible) nodeSprite.setColor(sf::Color::White);
    else nodeSprite.setColor(sf::Color(64, 64, 64, 128));
}

void StarNode::setLockVisible()
{
    lockVisible = true;
}

void StarNode::resize(float zoomFactor)
{
    auto size = nodeSprite.getGlobalBounds().getSize();
    if (size.x < 32.f && zoomFactor < 1.f) return;
    if (size.x > 96.f && zoomFactor > 1.f) return;
    nodeSprite.setScale(nodeSprite.getScale().x * zoomFactor, nodeSprite.getScale().y * zoomFactor);
}

unsigned StarNode::nextId = 0;

