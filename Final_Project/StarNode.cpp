#include <string>
#include "StarNode.h"
#include "Config.h"


StarNode::StarNode(float x, float y) : id(nextId++) {
    nodeShape.setRadius(15.f);
    nodeShape.setOrigin(15.f,15.f);
    nodeShape.setFillColor(sf::Color::Green);
    nodeShape.setPosition(x, y);


    text.setFont(FontManager::getInstance().fonts["font1"]); 
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setString(std::to_string(id));
    text.setPosition(
        nodeShape.getPosition().x + nodeShape.getRadius(),
        nodeShape.getPosition().y + nodeShape.getRadius());
}

void StarNode::draw(sf::RenderWindow& window) const {
    window.draw(nodeShape);
    window.draw(text);
}

sf::Vector2f StarNode::getPosition() const {
    return nodeShape.getPosition();
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
    if (visible) nodeShape.setFillColor(sf::Color::Green);
    else nodeShape.setFillColor(sf::Color(64,64,64));
}

void StarNode::setLockVisible()
{
    lockVisible = true;
}

void StarNode::resize(float zoomFactor)
{
    auto nodeSize = nodeShape.getRadius();
    nodeSize *= zoomFactor;
    nodeShape.setRadius(nodeSize);
    nodeShape.setOrigin(nodeSize, nodeSize);
}

unsigned StarNode::nextId = 0;

