#include "BFS.h"

BFS::BFS(Graph * g) {
    for (Vertex v : g->vertices) {
        v.label = "UNEXPLORED";
        for (Vertex w : g->vertices) {
            if(g->adjMatrix[v.index_][w.index_]) {
                v.adjacent.push_back(w);
            }
        }
    }
    for(Edge e : g->edgeList) {
        e.label = "UNEXPLORED";
    }
    for(Vertex v : g->vertices) {
        if (v.label == "UNEXPLORED") {
            traverse(g, v);
        }
    }
}

void BFS::traverse(Graph * g, Vertex v) {
    queue<Vertex> q;
    v.label = "VISITED";
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (Vertex w : v.adjacent) {
            if (w.label == "UNEXPLORED") {
                //label the edge between these two nodes a discovery edge
                g->edges[v.index_][w.index_].label = "DISCOVERY";
                w.label = "VISITED";
                w.parent_ = v.index_;
                w.distance_ = v.distance_ + 1;
                q.push(w);
            } else if (g->edges[v.index_][w.index_].label == "UNEXPLORED"){
                //label the edge between these two nodes a cross edge
                g->edges[v.index_][w.index_].label = "CROSS";
            }
        }
    }
}

vector<string> BFS::shortestPath(Graph * g, string v1, string v2) {
    return vector<string>();
}