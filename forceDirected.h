#pragma once

#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>

using namespace std;

class drawGraph {
    public:
        // draws the circls for the points
        void drawCircle(cs225::PNG* points);
        // outputs the final graph image
        cs225::PNG drawGraph(map<string, pair<int, int>>, Graph g, double threshold, int maxIter);
        Graph initialLayout();
        //calculates the slope between two points
        double calculateEdge()
    private:
        map<string, pair<int, int>> positions;

         
}