#pragma once

#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>

using namespace std;

class GraphVisualization {
    public:
        
        // outputs the final graph image
<<<<<<< HEAD
        map<string, pair<int, int>> constructForceDirectedGraph(map<string, pair<int, int>>, Graph* g,
                                                int maxIter, int length, float cooling);
=======
        map<string, pair<int, int>> constructForceDirectedGraph(map<string, pair<int, int>> layout, Graph* g,
                                                int maxIter, int length, float cooling, cs225::PNG* output);
>>>>>>> f880e4f3dd3c279938a72623a1d12ea95377d0e2
        // sets up a random layout of the graph
        map<string, pair<int,int>> initialLayout(Graph* g);
        map<string, pair<int,int>> getPositions();
        
        cs225::PNG* drawGraph(map<string, pair<int, int>> layout);
    private:
        // randomly picks a valid point within the space
        pair<int,int> pickPoint(cs225::PNG* output);
        map<string, pair<int,int>> positions;
        cs225::PNG * output;
        int maxIter;
        int length;
        float cooling;
};