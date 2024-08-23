#pragma once

#include <SFML/Graphics.hpp>
#include "StarNode.h"

class StarNodeWithEnemy : public StarNode
{
public:
	StarNodeWithEnemy(float x, float y);

	void dockPlayer(Ship* player) override;
	void setVisible(bool visible) override;
};
