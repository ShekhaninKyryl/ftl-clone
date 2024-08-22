#pragma once
#include <SFML/Graphics.hpp>
#include "StarNodeWithEnemy.h"

class StarNodeShadow : public StarNodeWithEnemy
{
public:
	StarNodeShadow(float x, float y);
	void setVisible(bool visible) override;
};
