
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
    //check for too large of an input
    if(src >= g->n || dest >= g->n) {
        return false;
    }
    //every vertex is connected to itself
    if(src == dest) {
        return true;
    }
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
}*/
//prints the adjacency matrix
void printGraph(Graph const * const g) {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < g->n; i += 1) {
                for (int j = 0; j < g->n; j += 1) {
                        bool neighbor = g->adjMatrix[i][j];
                        cout << neighbor << " ";
                }
                cout << "\n\n";
        }
}
//initializes the graph 
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


Graph* constructGraph(const string& filename, const string& filename2) {
    // Construct graph
    vector<Vertex> vertices;
    string line;
    int count = 0;
    //read in the file with all of the vertex names
    //the index of the vertex name in the vector is the vertex number it is in the adjacency matrix
    //code for reading and opening a file
    ifstream infile (filename);
    if (infile.is_open()) {
        //seperates every line in the file into a string
        while (getline(infile, line)) {
            // push all of the vertices
            //make sure that input file vertices are sorted!!! (if they are not this will not work)
            //makes a vertex with the string that is the name of the article and index of item added to the vector
            vertices.push_back(Vertex(line.substr(2), count));
            count++;
        }
    }
    //closes the file
    infile.close();
    //initializes the graph with the vertices we read from the file
    Graph* g = createVertices(vertices.size());
    g->vertices = vertices;
    g->n = vertices.size();

    //code for reading and opening a file
    ifstream infile2(filename2);
    if (infile2.is_open()) {
        //seperates every line in the file into a string
        while (getline(infile2, line)) {
            // push all of the edges
            //code for converting a string into two integers
            std::istringstream is(line);
            int src, dest; is >> src >> dest;
            //adds edge to adjacency matrix
            addEdge(g, src, dest);
        }
    }
    //closes the file
    infile2.close();
    return g;
}