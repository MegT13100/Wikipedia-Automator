#include "BFS.h"

BFS::BFS(Graph * g) {
    for (Vertex v : g->vertices) {
        for (Vertex w : g->vertices) {
            if(g->adjMatrix[v.index_][w.index_]) {
                g->adjacent[v.index_].push_back(w);
            }
        }
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
        for (Vertex w : g->adjacent[v.index_]) {
            if (w.label == "UNEXPLORED") {
                //label the edge between these two nodes a discovery edge
                g->edges[v.index_][w.index_].label = "DISCOVERY";
                w.label = "VISITED";
                q.push(w);
            } else if (g->edges[v.index_][w.index_].label == "UNEXPLORED"){
                //label the edge between these two nodes a cross edge
                g->edges[v.index_][w.index_].label = "CROSS";
            }
        }
    }
}
