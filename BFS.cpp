#include "BFS.h"

// cd cs225git/matatov-suminc2-mrtobin2-emilyc7
// random idea, but I feel like currently we need the two traversal and shortest path functions because we are doing a more straighforward implementation
// I think if we wanted to make it more efficient we could combine the two so that the traversal is from the first article name and that way shortest path
// will be more built in, but that will take some more

BFS::BFS(Graph * g) {
    for (Vertex * v : g->getVertices()) {
        v->label = "UNEXPLORED";
        for (Vertex * w : g->getVertices()) {
            if(g->getAdjMatrix()[v->index_][w->index_]) {
                v->adjacent.push_back(w);
            }
        }
    }

    for (Edge* e : g->getEdgeList()) {
        e->label = "UNEXPLORED";
    }

    for (Vertex * v : g->getVertices()) {
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
                g->getEdges()[v->index_][w->index_]->label = "DISCOVERY";
                w->label = "VISITED";
                w->parent_ = v->index_;
                w->distance_ = v->distance_ + 1;
                q.push(w);
            } else if (g->getEdges()[v->index_][w->index_]->label == "UNEXPLORED"){
                //label the edge between these two nodes a cross edge
                g->getEdges()[v->index_][w->index_]->label = "CROSS";
            }
        }
    }
}

//this is probably gonna be a really inelegant implementation, but I think it will work, feel free to modifiy it 
string BFS::shortestPath(Graph * g, string v1, string v2) {
    string toReturn;
    int first;
    int second;
    Vertex * a;
    Vertex * b;
    vector<string> firstHalf;
    vector<string> secondHalf;
    for (Vertex * v : g->getVertices()) {
        if (v->name_ == v1) {
            a = v;
            first = v->index_;
        }

        if (v->name_ == v2) {
            b = v;
            second = v->index_;
        }
    }

    while (a->parent_ != -1) {
        firstHalf.push_back(a->name_);
        a = g->getVertices()[a->parent_];
        if (a->parent_ == second) {
            firstHalf.push_back(b->name_);
            for(int i = 0; i < (int)firstHalf.size(); i++) {
                toReturn = toReturn + " " + firstHalf[i];
            }
            return toReturn;
        }
    }

    while (b->parent_ != -1) {
        secondHalf.push_back(b->name_);
        b = g->getVertices()[b->parent_];
        if (b->parent_ == first) {
            secondHalf.push_back(a->name_);
            for (int i = (int) secondHalf.size() - 1; i >= 0 ; i--) {
                toReturn = toReturn + " " + secondHalf[i];
            }
            return toReturn;
        }
    }

    cout << a->name_ <<endl;
    cout << b->name_ <<endl;
    for (int i = 0; i < (int)firstHalf.size(); i++) {
        toReturn = toReturn + " " + firstHalf[i];
    }

    for (int i = (int) secondHalf.size() - 1; i >= 0 ; i--) {
        toReturn = toReturn + " " + secondHalf[i];
    }

    return toReturn;
}