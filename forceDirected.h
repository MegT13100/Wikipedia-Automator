#pragma once

#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>

using namespace std;

class GraphVisualization {
    public:
        
        // outputs the final graph image
        map<string, pair<int, int>> constructForceDirectedGraph(map<string, pair<int, int>>, Graph* g,
                                                int maxIter, int length, float cooling);
        // sets up a random layout of the graph
        map<string, pair<int,int>> initialLayout(Graph* g);
        
        cs225::PNG* drawGraph(map<string, pair<int, int>> layout);
    private:
        // randomly picks a valid point within the space
        pair<int,int> pickPoint(cs225::PNG* output);
        map<string, pair<int,int>> positions;
        

         
};