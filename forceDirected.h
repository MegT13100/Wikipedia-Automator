#pragma once

#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>

using namespace std;

class GraphVisualization {
    public:
        
        // outputs the final graph image
        cs225::PNG drawForceDirectedGraph(map<string, pair<int, int>>, Graph g, double threshold, int maxIter);
        // sets up a random layout of the graph
        map<string, pair<int, int>> initialLayout(Graph g);
        // randomly picks a valid point within the space
        pair<int, int> pickPoint(cs225::PNG* output);
        
        cs225::PNG* drawGraph(map<string, pair<int, int>> layout);
    private:
        map<string, pair<int, int>> positions;

         
};