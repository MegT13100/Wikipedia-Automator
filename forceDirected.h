#pragma once

#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>
#include <vector>
#include <map>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <chrono>
#include <random>

using namespace std;

class GraphVisualization {
    public:
        
        // outputs the final graph image
        map<string, pair<int, int>> constructForceDirectedGraph(map<string, pair<int, int>> layout, Graph* g,
                                                int maxIter, int length, float cooling);
        // sets up a random layout of the graph
        map<string, pair<int,int>> initialLayout(Graph* g);
        map<string, pair<int,int>> getPositions();
        cs225::PNG * output;
        cs225::PNG* drawGraph(map<string, pair<int, int>> layout);
    private:
        // randomly picks a valid point within the space
        Graph * g;
        pair<int,int> pickPoint(cs225::PNG* output);
        map<string, pair<int,int>> positions;
        map<string, pair<int,int>> visited;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
};