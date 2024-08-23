#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {

    int width = Config::getInstance().windowWidth;
    int height = Config::getInstance().windowHeight;
    bool fullscreen = Config::getInstance().fullscreen;

    sf::Uint32 windowStyle = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;
    sf::VideoMode videoMode = fullscreen ? sf::VideoMode::getDesktopMode() : sf::VideoMode(width, height);

    sf::RenderWindow window(videoMode, "FTL - Clone", windowStyle);
    Game game(window);
    game.run();

    return 0;
}