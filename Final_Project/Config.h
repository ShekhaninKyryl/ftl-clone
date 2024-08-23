#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Config {
public:
    static Config& getInstance() {
        static Config instance; 
        return instance;
    }

    std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::Texture> textures;

    /*Window*/
    unsigned windowWidth;
    unsigned windowHeight;
    bool fullscreen;

    /*GamePlay*/
    std::string difficulty;

    /*Map*/
    unsigned numCluster;
    unsigned nodesPerCluster;
    float clusterRadius;
    float xSize;
    float ySize;
    unsigned starNodePct;
    unsigned starNodeShadowPct;
    unsigned starNodeWithEnemyPct;
    unsigned starNodeStorePct;

private:
    Config() {

        auto filepath = "config.json";
        std::ifstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "Could not open config file: " << filepath << std::endl;
        }

        json configJson;
        file >> configJson;

        /*Window*/
        windowWidth = configJson["window"]["width"];
        windowHeight = configJson["window"]["height"];
        fullscreen = configJson["window"]["fullscreen"];

        /*GamePlay*/
        difficulty = configJson["gameplay"]["difficulty"];

        /*Map*/
        numCluster = configJson["map"]["numCluster"];
        nodesPerCluster = configJson["map"]["nodesPerCluster"];
        clusterRadius = configJson["map"]["clusterRadius"];
        xSize = configJson["map"]["xSize"];
        ySize = configJson["map"]["ySize"];

        starNodePct = configJson["map"]["starNode"];
        starNodeShadowPct = configJson["map"]["starNodeShadow"];
        starNodeWithEnemyPct = configJson["map"]["starNodeWithEnemy"];
        starNodeStorePct = configJson["map"]["starNodeStore"];

        /*Font*/
        if (!fonts["font1"].loadFromFile(configJson["font"]["font1"])) {
            std::cout << "Can't load font1" << std::endl;
        }

        /*Texture*/

        //Ships
        if (!textures["playerShip"].loadFromFile(configJson["texture"]["playerShip"])) {
            std::cout << "Can't load playerShip" << std::endl;
        }

        //Nodes
        if (!textures["node"].loadFromFile(configJson["texture"]["node"])) {
            std::cout << "Can't load node" << std::endl;
        }
        if (!textures["node1"].loadFromFile(configJson["texture"]["node1"])) {
            std::cout << "Can't load node1" << std::endl;
        }

        if (!textures["nodeShadow"].loadFromFile(configJson["texture"]["nodeShadow"])) {
            std::cout << "Can't load nodeShadow" << std::endl;
        }
        if (!textures["nodeShadow1"].loadFromFile(configJson["texture"]["nodeShadow1"])) {
            std::cout << "Can't load nodeShadow1" << std::endl;
        }

        if (!textures["nodeStore"].loadFromFile(configJson["texture"]["nodeStore"])) {
            std::cout << "Can't load nodeStore" << std::endl;
        }
        if (!textures["nodeStore1"].loadFromFile(configJson["texture"]["nodeStore1"])) {
            std::cout << "Can't load nodeStore1" << std::endl;
        }

        if (!textures["nodeWithEnemy"].loadFromFile(configJson["texture"]["nodeWithEnemy"])) {
            std::cout << "Can't load nodeWithEnemy" << std::endl;
        }
        if (!textures["nodeWithEnemy1"].loadFromFile(configJson["texture"]["nodeWithEnemy1"])) {
            std::cout << "Can't load nodeWithEnemy1" << std::endl;
        }

        //Background
        if (!textures["background1"].loadFromFile(configJson["texture"]["background1"])) {
            std::cout << "Can't load background1" << std::endl;
        }
        if (!textures["background2"].loadFromFile(configJson["texture"]["background2"])) {
            std::cout << "Can't load background2" << std::endl;
        }
        if (!textures["background3"].loadFromFile(configJson["texture"]["background3"])) {
            std::cout << "Can't load background3" << std::endl;
        }
    }
};