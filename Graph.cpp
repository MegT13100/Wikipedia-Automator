
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
}*/

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
    //read in the file with all of the vertex names, the index of the vertex name in the vector is the vertex number it is in the adjacency matrix
    ifstream infile (filename);
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // push all of the vertices
            /*vector<string> v;
            const char delim = ' '; 
            std::vector<std::string> out; 
            std::stringstream ss(line); 
            std::string s;
            while (std::getline(ss, s, delim)) { 
                out.push_back(s); 
            } 
            for (auto &s: out) { 
                v.push_back(s);
            } */
            vertices.push_back(Vertex(line, count));
            count++;
        }
    }
    infile.close();
    Graph* g = createVertices(vertices.size());
    return g;
    
    /*ifstream infile2(filename2);
    if (infile2.is_open()) {
        while (getline(infile2, line)) {
            // push all of the vertices
            vector<string> v;
            string n;
            const char delim = ' '; 
            std::vector<std::string> out; 
            std::stringstream ss(line); 
            std::string s;
            while (std::getline(ss, s, delim)) { 
                out.push_back(s); 
            } 
            for (auto &s: out) { 
                if(count != 0) {
                    n += s;
                }
            } 
            v.push_back(s);
            //converts the string number into an int, found on stackoverflow, feel free to modify to be more elegant
            int src;
            int dest;
            stringstream first(v[0]);
            stringstream second(v[1]);
            first >> src;
            second >> dest;
            addEdge(g, src, dest);
        }
    }
    infile2.close();*/
}