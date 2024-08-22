#include "Game.h"



Game::Game() : window(sf::VideoMode(1200.f, 1000.f), "FTL Clone"), playerShip(100.f, 100.f) {
    auto w_view = window.getView();
    view.setSize(w_view.getSize()); // Initial view size
    view.setCenter(w_view.getCenter()); // Center the view
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


        // ���������� ���������� ������ ����
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            // ����������, �� ��������� �� �����
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
            // Get the scroll amount
            float zoomFactor = 1.f;
            if (event.mouseWheelScroll.delta > 0) {
                zoomFactor = 0.9f; // Zoom out (decrease size)
            }
            else if (event.mouseWheelScroll.delta < 0) {
                zoomFactor = 1.1f; // Zoom in (increase size)
            }

            map->resizeNodes(zoomFactor);
            playerShip.resize(zoomFactor);

            // Adjust view size
            sf::Vector2f viewSize = view.getSize();
            viewSize *= zoomFactor;
            view.setSize(viewSize);

            // Optionally, adjust the view center to keep the same point under the mouse cursor
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f worldMousePosition = window.mapPixelToCoords(mousePosition, view);
            view.setCenter(worldMousePosition);

            window.setView(view);
        }
    }
}

void Game::update(sf::Time deltaTime) {
    // ��������� ���� �������
    playerShip.update(deltaTime.asSeconds(), map);

    gameUI->update();
}

void Game::render() {
    window.clear();

    updateView(window, playerShip.getPosition());
    
    // ������� �����
    map->draw(window);

    playerShip.draw(window);

    // ������������ ����������� ��� ��� UI
    window.setView(window.getDefaultView());
    gameUI->render(window);

    window.setView(view);
    window.display();
}

void Game::updateView(sf::RenderWindow& window, const sf::Vector2f& playerPosition)
{
    {
        view.setCenter(playerPosition);   // Set the view's center to the player's position
        window.setView(view);             // Apply the view to the window
    }
}
