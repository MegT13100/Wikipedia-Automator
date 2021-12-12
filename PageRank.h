#pragma once

#include "Graph.h"
#include <map>

class PageRank {
    public:
        PageRank(Graph* g);
        vector<double> FindPageRanks(double d, size_t num_iterations);

    private:
        map<int, vector<int>> getInboundLinks();
        double** CreateMatrix();
        void PowerMethod(double** matrix);

        Graph* graph_;
};