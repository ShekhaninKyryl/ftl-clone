#pragma once

#include "Config.h"

class UI_Base
{
public:
	UI_Base() {};
	virtual void update() {};
	virtual void render(sf::RenderWindow& window) {};
};