#pragma once

#include <SFML/Graphics.hpp>
#include "StarNode.h"

class StarNodeStore : public StarNode
{
public:
	StarNodeStore(float x, float y);
	void setVisible(bool visible) override;
	void dockPlayer(Ship* player) override;

	bool isStore = false;
};
