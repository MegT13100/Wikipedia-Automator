#include "BFS.h"


/**
 * @brief constructor of BFS class, performs the traversal on the graph
 * @param the graph to traverse
 */
BFS::BFS(Graph * g) {

    for (Vertex * v : g->getVertices()) {
        if (v->label == "UNEXPLORED") {
            traverse(g, v);
        }
    }
}

/**
 * @brief helper function for traversing the graph
 * @param g graph to traverse 
 * @param v vertex to begin the traversal on
 */
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

/**
 * @brief constructor of BFS class, performs the traversal on the graph
 * @param g the graph to traverse
 * @param v1 name of first vertex
 * @param v2 name of second vertex
 * @return string of the names of vertices creating the shortest path
 */
string BFS::shortestPath(Graph * g, string v1, string v2) {
    if(v1 == v2) {
        return " " + v1;
    } 
    string toReturn;
    int first = -1;
    int second = -1;
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

    if(first == -1) {
        return v1 + " does not exist in this dataset";
    }

    if(second == -1) {
        return v2 + " does not exist in this dataset";
    }

    while (a->parent_ != -1) {
        firstHalf.push_back(a->name_);
        a = g->getVertices()[a->parent_];
        if (a->index_ == second) {
            firstHalf.push_back(a->name_);
            for(int i = 0; i < (int)firstHalf.size(); i++) {
                toReturn = toReturn + " " + firstHalf[i];
            }
            return toReturn;
        }
    }

    while (b->parent_ != -1) {
        secondHalf.push_back(b->name_);
        b = g->getVertices()[b->parent_];
        if (b->index_ == first) {
            secondHalf.push_back(b->name_);
            for (int i = (int) secondHalf.size() - 1; i >= 0 ; i--) {
                toReturn = toReturn + " " + secondHalf[i];
            }
            return toReturn;
        }
    }
    firstHalf.push_back(a->name_);
    secondHalf.push_back(b->name_);
    for (int i = 0; i < (int)firstHalf.size(); i++) {
        toReturn = toReturn + " " + firstHalf[i];
    }

    for (int i = (int) secondHalf.size() - 1; i >= 0 ; i--) {
        toReturn = toReturn + " " + secondHalf[i];
    }

    return toReturn;
}