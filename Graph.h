#include <iostream>
#include <string>
#include <sstream>


#ifndef _GRAPH_
#define _GRAPH_
using namespace std;

struct Graph {
        bool** adjMatrix;
        int n;
};
struct Vertex {
        Vertex() {
                name_ = "";
                index_ = -1;
        }
        Vertex(string name, string index) {
                name_ = name;
                stringstream i(index);
                i >> index_;
        }
        string name_;
        int index_;
};

bool containsEdge(Graph const * const g, int src, int dest);

void addEdge(Graph* g, int src, int dest);

/*int numOutgoingEdges(Graph const * const g, int v);

int numIncomingEdges(Graph const * const g, int v);

void printGraph(Graph const * const g);*/

Graph* createVertices(int numV);

void ConstructGraph(const string& filename, const string& filename2);

#endif