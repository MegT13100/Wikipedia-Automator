#pragma once

#include "Graph.h"
#include <map>
#include <queue>

enum Label { UNEXPLORED, DISCOVERY, CROSS };

class BFS {
    public:
        BFS(Graph * g);
        void traverse(Graph * g, Vertex v);
        vector<string> shortestPath(Graph * g, string v1, string v2);
    private:
        //Graph * graph_;
        map<Vertex, bool> visited_;
        //queue<Vertex> q;
};