#pragma once

#include <SFML/Graphics.hpp>
#include "StarNode.h"

class StarNodeShadow : public StarNode
{
public:
	StarNodeShadow(float x, float y);
	void setVisible(bool visible) override;
	void dockPlayer(Ship* player) override;
};
