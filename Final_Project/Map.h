#pragma once

#include <queue>
#include <unordered_map>
#include <vector>
#include <iterator>

#include "StarNode.h"
#include "StarNodeWithEnemy.h"
#include "StarNodeStore.h"
#include "StarNodeShadow.h"
#include "Config.h"

#include "Random.h"

class Map {
public:
   Map(unsigned nodesCount) : maxEdges(2)
    {
        auto config = Config::getInstance();
        generateClusteredNodes(config.numCluster, config.nodesPerCluster, config.clusterRadius);

        adjacencyList.resize(nodes.size());

        
        hubLinking();
        neighborLinking(config.clusterRadius);

        return;
    }

    void addEdge(StarNode* x, StarNode* y);
    void addEdge(sf::Vector2f x, sf::Vector2f y);
    void draw(sf::RenderWindow& window);
    void higlightNodes(unsigned nodeId);
    void hideNodes(unsigned nodeId);
    std::vector<StarNode*> getlinkedNodes(unsigned nodeId);
    void resizeNodes(float zoomFactor);


    void neighborLinking(float radius);

    void hubLinking();

    void generateClusteredNodes(unsigned numClusters, unsigned nodesPerCluster, float clusterRadius);

public:
    std::vector<StarNode*> nodes;

private:
    std::vector<std::list<StarNode*>> adjacencyList;
    std::vector<StarNode*> hubNodes;
    unsigned maxEdges;
};

