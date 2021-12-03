#include "BFS.h"

// cd cs225git/matatov-suminc2-mrtobin2-emilyc7
//random idea, but I feel like currently we need the two traversal and shortest path functions because we are doing a more straighforward implementation
//I think if we wanted to make it more efficient we could combine the two so that the traversal is from the first article name and that way shortest path
//will be more built in, but that will take some more

BFS::BFS(Graph * g) {
    for (Vertex * v : g->vertices) {
        v->label = "UNEXPLORED";
        for (Vertex * w : g->vertices) {
            if(g->adjMatrix[v->index_][w->index_]) {
                v->adjacent.push_back(w);
            }
        }
    }
    for(Edge e : g->edgeList) {
        e.label = "UNEXPLORED";
    }
    for(Vertex * v : g->vertices) {
        if (v->label == "UNEXPLORED") {
            traverse(g, v);
        }
    }
}

void BFS::traverse(Graph * g, Vertex * v) {
    queue<Vertex*> q;
    v->label = "VISITED";
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (Vertex * w : v->adjacent) {
            if (w->label == "UNEXPLORED") {
                //label the edge between these two nodes a discovery edge
                g->edges[v->index_][w->index_].label = "DISCOVERY";
                w->label = "VISITED";
                w->parent_ = v->index_;
                w->distance_ = v->distance_ + 1;
                q.push(w);
            } else if (g->edges[v->index_][w->index_].label == "UNEXPLORED"){
                //label the edge between these two nodes a cross edge
                g->edges[v->index_][w->index_].label = "CROSS";
            }
        }
    }
}

//this is probably gonna be a really inelegant implementation, but I think it will work, feel free to modifiy it 
vector<string> BFS::shortestPath(Graph * g, string v1, string v2) {
    int first;
    int second;
    Vertex * a;
    Vertex * b;
    vector<string> firstHalf;
    vector<string> secondHalf;
    for(Vertex * v : g->vertices) {
        if(v->name_ == v1) {
            a = v;
            first = v->index_;
        }
        if(v->name_ == v2) {
            b = v;
            second = v->index_;
        }
    }
    while(a->parent_ != -1) {
        firstHalf.push_back(a->name_);
        a = g->vertices[a->parent_];
        if(a->parent_ == second) {
            firstHalf.push_back(b->name_);
            return firstHalf;
        }
    }
    while(b->parent_ != -1) {
        secondHalf.push_back(b->name_);
        b = g->vertices[b->parent_];
        if(b->parent_ == first) {
            secondHalf.push_back(a->name_);
            return secondHalf;
        }
    }
    return firstHalf;
}