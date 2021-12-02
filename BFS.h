#pragma once

#include "Graph.h"
#include <map>

enum Label { UNEXPLORED, DISCOVERY, CROSS }

class BFS {
    public:
        BFS(Graph g);
        traverse(Graph g, Vertex v);
    private:
        Graph graph_;
        map<Vertex, bool> visited_;
};