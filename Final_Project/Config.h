#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

class FontManager {
public:
    static FontManager& getInstance() {
        static FontManager instance; 
        return instance;
    }

    std::map<std::string, sf::Font> fonts;

private:
    FontManager() {
        // Add resources
        // Add config file
        if (!fonts["font1"].loadFromFile("arial.ttf")) {
            std::cout << "Can't load font1" << std::endl;
        }
    }
};