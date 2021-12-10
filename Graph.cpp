#include "Graph.h"

#include <iostream>
#include <fstream>
#include <sstream> 

#include <string> 
#include <vector>
#include <cstdio>
#include <algorithm> 

using std::string;
using std::vector;
using std::ifstream;
using namespace std;

/*Graph::Graph(string name1, string name2) {
    g = constructGraph(name1, name2);
}*/

bool containsEdge(Graph const * const g, int src, int dest) {
    // Check if an input is too large
    if (src >= g->getNumV() || dest >= g->getNumV()) {
        return false;
    }

    // Every vertex is connected to itself
    if (src == dest) {
        return true;
    }

    // If the relationship between these two vertices is marked true in the adjacency matrix, then the edge exists
    if (g->adjMatrix[src][dest]) {
        return true;
    }

    return false;
}

void addEdge(Graph* g, int src, int dest) {
    // Add an edge between the given vertices
    // NOTE: since this is an directed graph, we only need to add in to the source
    Edge* edge = new Edge(*g->getVertices()[src], *g->getVertices()[dest]);
    g->getEdges()[src][dest]= edge;
    // g->getEdges()[dest][src]= edge;

    g->getEdgeList().push_back(edge);

    // Increment the degree of the vertex
    g->getVertices()[src]->degree_++;

    // Mark as true on the matrix
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

/*int Graph::numOutgoingEdges(Graph const * const g, int v) {
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if( g->adjMatrix[v][i] == 1) {
            count++;
        }
    }
    return count;
}

int Graph::numIncomingEdges(Graph const * const g, int v) {
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if( g->adjMatrix[i][v] == 1) {
            count++;
        }
    }
    return count;
}*/

// Prints the adjacency matrix
void printGraph(Graph const * const g) {
    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < g->getNumV(); i += 1) {
        for (int j = 0; j < g->getNumV(); j += 1) {
            bool neighbor = g->adjMatrix[i][j];
            cout << neighbor << " ";
        }
        cout << "\n\n";
    }
}

// Initializes the graph 
Graph* createVertices(int numV) {
    //creates an empty graph with numV vertices and initializes all edges to false
    Graph* g = new Graph();
    g->setNumV(numV);
    g->adjMatrix = new bool*[numV];
    for (int i = 0; i < numV; i += 1) {
        g->adjMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j += 1) {
            if(i == j) {
                g->adjMatrix[i][j] = 1;
            } else {
                g->adjMatrix[i][j] = 0;
            }
        }
    }
    return g;
}

Graph* constructGraph(const string& filename, const string& filename2) {
    // Construct graph
    vector<Vertex*> vertices;
    string line;
    int count = 0;

    // read in the file with all of the vertex names
    // the index of the vertex name in the vector is the vertex number it is in the adjacency matrix
    // code for reading and opening a file
    ifstream infile (filename);
    if (infile.is_open()) {
        // seperates every line in the file into a string
        while (getline(infile, line)) {
            // push all of the vertices
            // make sure that input file vertices are sorted!!! (if they are not this will not work)
            // makes a vertex with the string that is the name of the article and index of item added to the vector
            vertices.push_back(new Vertex(line.substr(2), count));
            count++;
        }
    }

    // closes the file
    infile.close();
    // initializes the graph with the vertices we read from the file
    Graph* g = createVertices(vertices.size());
    g->setVertices(vertices);
    g->setNumV(vertices.size());
    g->setEdges(vector<vector<Edge*>>(g->getNumV(), vector<Edge*>(g->getNumV(), new Edge)));

    // code for reading and opening a file
    ifstream infile2(filename2);
    if (infile2.is_open()) {
        // seperates every line in the file into a string
        while (getline(infile2, line)) {
            // push all of the edges
            // code for converting a string into two integers
            std::istringstream is(line);
            int src, dest; is >> src >> dest;
            // adds edge to adjacency matrix
            addEdge(g, src, dest);
        }
    }
    // closes the file
    infile2.close();
    return g;
}

/*bool** Graph::getAdjMatrix() const {
    return adjMatrix;
}*/

vector<Vertex*> Graph::getVertices() const {
    return vertices;
}
void Graph::setVertices(vector<Vertex*> verts) {
    vertices = verts;
}
vector<Edge*> Graph::getEdgeList() const {
    return edgeList;
}
vector<vector<Edge*>> Graph::getEdges() const {
    return edges;
}
void Graph::setEdges(vector<vector<Edge*>> e) {
    edges = e;
}
int Graph::getNumV() const {
    return numV;
}
void Graph::setNumV(int n_) {
    numV = n_;
}
