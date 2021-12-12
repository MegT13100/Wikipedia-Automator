#pragma once

#include "Graph.h"

class PageRank {
    public:
        PageRank();

    private:
        double** createMatrix(Graph* g);
};