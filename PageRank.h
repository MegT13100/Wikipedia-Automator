#pragma once

#include "Graph.h"
#include <map>

/**
*
*/
class PageRank {
    public:
        /**
        * 
        * @param
        */
        PageRank(Graph* g);

        /**
        *
        * @param
        */
        vector<double> FindPageRanks(double d, size_t num_iterations);

        /**
        * 
        */
        map<int, vector<int>> getInboundLinks();

        /*
        *
        */
        double** CreateMatrix();

        /**
        * 
        * @param
        */
        void PowerMethod(double** matrix);

    private:
        Graph* graph_;
};