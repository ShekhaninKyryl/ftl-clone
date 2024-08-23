#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Ship;
class EnemyShip;


class StarNode
{
public:
	StarNode(float x, float y);
	void draw(sf::RenderWindow& window) const;

	sf::Vector2f getPosition() const;
	unsigned getId() const;
	static unsigned getLastId();

	void undockPlayer();
	virtual void dockPlayer(Ship* player);

	bool operator==(const StarNode& other) const {
		return id == other.id;
	}

	bool operator!=(const StarNode& other) const {
		return id != other.id;
	}

	virtual void setVisible(bool visible);
	void setLockVisible();
	void resize(float zoomFactor);

	Ship *player = nullptr;
	EnemyShip* enemy = nullptr;

	bool isVisible = false;
	bool lockVisible = false;

protected:
	sf::Sprite nodeSprite;
	sf::Texture* texture;

private:
	unsigned id;
	static unsigned nextId;
};