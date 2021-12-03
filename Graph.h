#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>

#ifndef _GRAPH_
#define _GRAPH_
using namespace std;

struct Vertex {
        Vertex() {
                name_ = "";
                index_ = -1;
                string parent_ = "";
                label = "UNEXPLORED";
        }
        Vertex(string name, int index) {
                name_ = name;
                index_ = index;
                label = "UNEXPLORED";
        }
        string name_;
        int index_;
        string parent_;
        int distance_;
        //vector<int> AdjEdges;
        string label;
};
struct Edge {
        Edge() {
                u = Vertex();
                v = Vertex();
                label = "UNEXPLORED";
        }
        Edge(Vertex u, Vertex v) {
                this->u = u;
                this->v = v;
                label = "UNEXPLORED";
        }
        Vertex u;
        Vertex v;
        string label;
};
struct Graph {
        //map<Edge, bool>** adjMatrix;
        bool** adjMatrix;
        //number of vertices in the graph
        int n;
        //vector of all vertices
        vector<Vertex> vertices;
        //vector of all edges (make 2D)
        vector<vector<Edge>> edges;
        //map that contains all the adjacent edges for a given vertex
        std::unordered_map<int, vector<Vertex>> adjacent;
};

bool containsEdge(Graph const * const g, int src, int dest);

void addEdge(Graph* g, int src, int dest);

/*int numOutgoingEdges(Graph const * const g, int v);

int numIncomingEdges(Graph const * const g, int v);*/

void printGraph(Graph const * const g);

Graph* createVertices(int numV);

Graph* constructGraph(const string& filename, const string& filename2);

vector<Vertex> getVertices();

vector<Edge> getEdges();

#endif

