#include "Game.h"



Game::Game() : window(sf::VideoMode(1200.f, 1000.f), "FTL Clone"), playerShip(100.f, 100.f), currentState(GameState::Map) {
    auto w_view = window.getView();
    view.setSize(w_view.getSize());
    view.setCenter(w_view.getCenter());
    window.setView(view);

    map = new Map(20);

    for (const auto& node : map->nodes) {
        node->setVisible(false);
    }

    playerShip.dockToStar(map->nodes[0], map);
    map->higlightNodes(map->nodes[0]->getId());


    gameUI = new UI(&playerShip);
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        processEvents();
        sf::Time deltaTime = clock.restart();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (currentState == GameState::Map) {

            // Перевіряємо натискання кнопки миші
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // Перевіряємо, чи натиснуто на вузол
                playerShip.getStar()->getId();
                for (const auto& node : map->getlinkedNodes(playerShip.getStar()->getId())) {
                    sf::Vector2f nodePos = node->getPosition();
                    if (sqrt(pow(mousePos.x - nodePos.x, 2) + pow(mousePos.y - nodePos.y, 2)) < 20.f) {
                        playerShip.moveTo(node, map);
                    }
                }
            }

            // Zoom
            if (event.type == sf::Event::MouseWheelScrolled) {
                float zoomFactor = 1.f;
                if (event.mouseWheelScroll.delta > 0) {
                    zoomFactor = 0.9f;
                }
                else if (event.mouseWheelScroll.delta < 0) {
                    zoomFactor = 1.1f;
                }

                map->resizeNodes(zoomFactor);
                playerShip.resize(zoomFactor);

                // Adjust view size
                sf::Vector2f viewSize = view.getSize();
                viewSize *= zoomFactor;
                view.setSize(viewSize);

                // adjust the view center to keep the same point under the mouse cursor
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f worldMousePosition = window.mapPixelToCoords(mousePosition, view);
                view.setCenter(worldMousePosition);

                window.setView(view);
            }
        }
        if (currentState == GameState::Battle) {
            //Fight control
        }
    }
}

void Game::update(sf::Time deltaTime) {
    auto playerNode = playerShip.getStar();

    if (currentState == GameState::Map) {
        playerShip.update(deltaTime.asSeconds(), map);

        if (playerNode->player && playerNode->enemy && fight == nullptr) {
            fight = new Fight(playerNode->player, playerNode->enemy);
            currentState = GameState::Battle;
        }
    } 
    if (currentState == GameState::Battle) {
        if (fight) {
            auto fightResult = fight->update(deltaTime.asSeconds());
            switch (fightResult)
            {
            case FightState::Win: {
                // use win case
                break;
            }
            case FightState::Lose: {
                //use lose case
                break;
            }
            default: break;
            };

            if (fightResult == FightState::Win || fightResult == FightState::Lose) {
                delete playerNode->enemy;
                playerNode->enemy = nullptr;
                delete fight;
                fight = nullptr;
                currentState = GameState::Map;
            }
        }

    }

    gameUI->update();
}

void Game::render() {
    window.clear();

    if (currentState == GameState::Map) {
        // Draw Map
        updateView(window, playerShip.getPosition());
        // Draw Nodes, Edges
        map->draw(window);

        playerShip.draw(window);
    }
    else if (currentState == GameState::Battle) {
        // Draw Battle
    }

   

    // Set standart view for UI
    window.setView(window.getDefaultView());
    gameUI->render(window);
    

    window.setView(view);
    window.display();
}

void Game::updateView(sf::RenderWindow& window, const sf::Vector2f& playerPosition)
{
    {
        view.setCenter(playerPosition);
        window.setView(view);
    }
}
