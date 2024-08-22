// FontManager.h
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

class FontManager {
public:
    static FontManager& getInstance() {
        static FontManager instance; // Guaranteed to be destroyed, instantiated on first use
        return instance;
    }

    std::map<std::string, sf::Font> fonts;

private:
    FontManager() {
        if (!fonts["font1"].loadFromFile("arial.ttf")) {
            std::cout << "Can't load font1" << std::endl;
        }
    }
};