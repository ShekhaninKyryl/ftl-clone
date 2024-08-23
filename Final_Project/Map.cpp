#include "Map.h"


void Map::addEdge(StarNode* x, StarNode* y)
{
    auto& adjacencyX = adjacencyList[x->getId()];
    if (std::find(adjacencyX.begin(), adjacencyX.end(), y) == adjacencyX.end()) {
        adjacencyX.push_back(y);  // Only add if the edge doesn't exist
    }

    auto& adjacencyY = adjacencyList[y->getId()];
    if (std::find(adjacencyY.begin(), adjacencyY.end(), x) == adjacencyY.end()) {
        adjacencyY.push_back(x);  // Only add if the edge doesn't exist
    }
}

void Map::addEdge(sf::Vector2f firstNode, sf::Vector2f seconedNode)
{
    addEdge(new StarNode(firstNode.x, firstNode.y), new StarNode(seconedNode.x, seconedNode.y));
}

void Map::draw(sf::RenderWindow& window)
{

    for (unsigned i = 0; i < nodes.size(); ++i) {

        const StarNode& node = *nodes[i];


        if (node.isVisible) {
            // For each neighbor of the node, draw a line to it
            for (const StarNode* neighbor : adjacencyList[i]) {
                sf::VertexArray line(sf::Lines, 2);

                line[0].position = node.getPosition();
                line[0].color = sf::Color(255, 255, 255, 30);



                line[1].position = neighbor->getPosition();
                line[1].color = sf::Color(255, 255, 255, 30);

                window.draw(line);
            }
        }
        node.draw(window);
    }
}

void Map::higlightNodes(unsigned nodeId)
{
    for (StarNode* neighbor : adjacencyList[nodeId]) {
        neighbor->setVisible(true);  // Set all neighbors as visible
    }
}

void Map::hideNodes(unsigned nodeId)
{
    for (StarNode* neighbor : adjacencyList[nodeId]) {
        neighbor->setVisible(false);  // Set all neighbors as hidden
    }
}

std::vector<StarNode*> Map::getlinkedNodes(unsigned nodeId)
{
    auto& list = adjacencyList[nodeId];
    std::vector<StarNode*> vector(list.begin(), list.end());

    return vector;
}

void Map::resizeNodes(float zoomFactor)
{
    for (auto node : nodes) node->resize(zoomFactor);
}

void Map::neighborLinking(float radius)
{
        std::vector<unsigned> linkingCounter(nodes.size(), 0);  // Keeps track of the number of links per node

        for (auto node : nodes) {
            auto nodePosition = node->getPosition();
            std::vector<StarNode*> closeNodes;  // To store nodes within the radius

            // Check all nodes to see if they are within the radius of the current node
            for (const auto& potentialNeighbor : nodes) {
                if (node == potentialNeighbor) {
                    continue;  // Skip self
                }

                auto neighborPosition = potentialNeighbor->getPosition();

                // Calculate Euclidean distance between the nodes
                float distance = std::sqrt(
                    std::pow(nodePosition.x - neighborPosition.x, 2) +
                    std::pow(nodePosition.y - neighborPosition.y, 2)
                );

                // Check if the distance is within the radius
                if (distance <= radius) {
                    closeNodes.push_back(potentialNeighbor);
                }
            }


            for (auto closeNode : closeNodes) {
                if (adjacencyList[node->getId()].size() > maxEdges) break;
                addEdge(node, closeNode);
            }
        }
}

void Map::hubLinking()
{
    for (auto it1 = hubNodes.begin(); it1 != hubNodes.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != hubNodes.end(); ++it2) {
            addEdge(*it1, *it2);  // Link each pair of nodes
        }
    }
}

void Map::generateClusteredNodes(unsigned numClusters, unsigned nodesPerCluster, float clusterRadius)
{
    auto config = Config::getInstance();
    for (unsigned i = 0; i < numClusters; ++i) {
        // Generate hub node for the cluster
        float hubX = randomFloat(100.f, config.xSize);
        float hubY = randomFloat(100.f, config.ySize);
        StarNode* hubNode = new StarNode(hubX, hubY);
        hubNodes.push_back(hubNode);

        nodes.push_back(hubNode);

        // Generate child nodes around the hub
        for (unsigned j = 0; j < nodesPerCluster; ++j) {
            float angle = randomFloat(0, 2 * 3.14159f);
            float distance = randomFloat(50.f, clusterRadius) + 20;

            float nodeX = hubX + cos(angle) * distance;
            float nodeY = hubY + sin(angle) * distance;

            // Randomly decide the type of node
            // Add config
            const unsigned chooseStarNumber = randomInt(0, 9);
            if (chooseStarNumber < config.starNodePct) {
                nodes.push_back(new StarNode(nodeX, nodeY));
                continue;
            }
            else if (chooseStarNumber < config.starNodeShadowPct) {
                nodes.push_back(new StarNodeShadow(nodeX, nodeY));
                continue;
            }
            else if (chooseStarNumber < config.starNodeWithEnemyPct) {
                nodes.push_back(new StarNodeWithEnemy(nodeX, nodeY));
                continue;
            } else nodes.push_back(new StarNodeStore(nodeX, nodeY));
        }
    }
}
