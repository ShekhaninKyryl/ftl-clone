#pragma once

#include <vector>

#include "UI_Player.h"


class UI
{
public:
	UI(Ship *player) {
		UIs.push_back(new UI_Player(player));
	};

	void update() {
		for (auto ui : UIs) ui->update();
	};

	void render(sf::RenderWindow& window) {
		for (auto ui : UIs) ui->render(window);
	};

private:
	std::vector<UI_Base*> UIs;
};
