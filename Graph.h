#include <iostream>
#include <string>
#include <vector>

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
                string parent_ = "";
        }
        Vertex(string name, int index) {
                name_ = name;
                //converts the string number into an int, found on stackoverflow, feel free to modify to be more elegant
                index_ = index;
        }
        string name_;
        int index_;
        string parent_;
};

bool containsEdge(Graph const * const g, int src, int dest);

void addEdge(Graph* g, int src, int dest);

/*int numOutgoingEdges(Graph const * const g, int v);

int numIncomingEdges(Graph const * const g, int v);*/

void printGraph(Graph const * const g);

Graph* createVertices(int numV);

Graph* constructGraph(const string& filename, const string& filename2);

#endif
