
#include "Graph.h"

#include <cstdio>
#include <vector>
#include <algorithm> 
#include <fstream>
#include <iostream>
#include <string> 
#include <sstream> 

using std::string;
using std::vector;
using std::ifstream;
using namespace std;

bool containsEdge(Graph const * const g, int src, int dest) {
    //if the relationship between these two vertices is marked true in the adjacency matrix, then the edge exists
    if(g->adjMatrix[src][dest]) {
        return true;
    }
    return false;
}

void addEdge(Graph* g, int src, int dest) {
    //add an edge between the given vertices, since this is an undirected graph, need to add it in both directions.
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

/*int numOutgoingEdges(Graph const * const g, int v) {
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if( g->adjMatrix[v][i] == 1) {
            count++;
        }
    }
    return count;
}

int numIncomingEdges(Graph const * const g, int v) {
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if( g->adjMatrix[i][v] == 1) {
            count++;
        }
    }
    return count;
}

void printGraph(Graph const * const g) {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < g->n; i += 1) {
                for (int j = 0; j < g->n; j += 1) {
                        bool neighbor = g->adjMatrix[i][j];
                        cout << neighbor << " ";
                }
                cout << "\n\n";
        }
}*/

Graph* createVertices(int numV) {
    //creates an empty graph with numV vertices and initializes all edges to false
    Graph* g = new Graph();
    g->n = numV;
    g->adjMatrix = new bool*[numV];
    for (int i = 0; i < numV; i += 1) {
        g->adjMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j += 1) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}

vector<Vertex> getVertices() const {
    return vector<Vertex>();
}

vector<Edge> getEdges() const {
    return vector<Edge>();
}