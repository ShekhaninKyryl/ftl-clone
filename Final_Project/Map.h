#pragma once

#include <queue>
#include <unordered_map>
#include <vector>
#include <iterator>

#include "Random.h"
#include "StarNode.h"
#include "StarNodeWithEnemy.h"
#include "StarNodeStore.h"
#include "StarNodeShadow.h"

class Map {
public:
   Map(unsigned nodesCount) : maxEdges(2)
    {
        generateClusteredNodes(5, nodesCount / 3, 200);

        adjacencyList.resize(nodes.size());

        neighborLinking(200);
        hubLinking();

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

