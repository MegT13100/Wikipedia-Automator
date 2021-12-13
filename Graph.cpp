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

/**
 * @brief searches the adjacency matrix to see if the edge exists
 * @param g pointer to the graph to search
 * @param src index of the source vertex for the edge
 * @param dest index of the destination vertex for the edge
 * @return if the edge exists or not
 */

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

/**
 * @brief adds an edge to the graph
 * @param g pointer to the graph where edges will be added
 * @param src index of the source vertex for the edge
 * @param dest index of the destination vertex for the edge
 */
void addEdge(Graph* g, int src, int dest) {
    // Add an edge between the given vertices
    // NOTE: since this is a directed graph, we only need to add in to the source
    if(src >= g->getNumV() || src >= g->getNumV()) {
        return;
    }
    Edge* edge = new Edge(*g->getVertices()[src], *g->getVertices()[dest]);
    //adds edge to adjacency matrix
    g->getEdges()[src][dest]= edge;

    //adds edge to the edge list
    g->getEdgeList().push_back(edge);

    //Increment the degree of the vertex
    g->getVertices()[src]->degree_++;

    //add edge to adjecency list
    g->getVertices()[src]->adjacent.push_back(g->getVertices()[dest]);

    // Mark as true on the matrix
    g->adjMatrix[src][dest] = 1;
}

/**
 * @brief print the adjacency matrix associated with the given graph
 * @param g pointer to the graph to print
 */
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

/**
 * @brief creates an empty graph with numV vertices and initializes all edges to false
 * @param numV number of vertices
 * @return pointer to a graph object
 */
Graph* createVertices(int numV) {
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

<<<<<<< HEAD
Graph* constructGraph(const string& filename, const string& filename2) {
=======
/**
 * @brief creates a graph from two data files: one with the vertices and the second with the edges
 * @param filename file with vertices formatted 0 Vertex Name
 * @param filename2 file with edges formatted 0 100
 * @param numData number of datapoints from the file that should be read in 
 * @return pointer to a graph object
 */
Graph* constructGraph(const string& filename, const string& filename2, int nData) {
>>>>>>> 260158841ed06f53dd4061c04443cc7fed8d5393
    // Construct graph
    vector<Vertex*> vertices;
    string line;
    // read in the file with all of the vertex names
    // the index of the vertex name in the vector is the vertex number it is in the adjacency matrix
    // code for reading and opening a file
    ifstream infile (filename);
    if (infile.is_open()) {
        // seperates every line in the file into a string
        while (getline(infile, line)) {
            // makes a vertex with the string that is the name of the article and index before the name
            std::istringstream is(line);
            std::string name;
            std::string word;
            //assigns index to the index in the file
            int index; 
            is >> index;
<<<<<<< HEAD
            //if(index > nData) {
                //break;
            //}
=======
            //making sure the index is smaller than the graph size
            if(index > nData) {
                break;
            }
            //creates a string with the article name
>>>>>>> 260158841ed06f53dd4061c04443cc7fed8d5393
            while (is >> word) {
                name = name + " " + word;
            }
            //push back the vertex with the name and index created
            vertices.push_back(new Vertex(name.substr(1), index));
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
            // code for getting the index for the vertices in the edge
            std::istringstream is(line);
            int src, dest; is >> src >> dest;
<<<<<<< HEAD
            // adds edge to adjacency matrix
            //if(src > nData || dest > nData) {
                //continue;
            //}
=======
            // adds edge to adjacency matrix, making sure that it is not an edge between a vertex that is larger than the graph
            if(src > nData || dest > nData) {
                continue;
            }
>>>>>>> 260158841ed06f53dd4061c04443cc7fed8d5393
            addEdge(g, src, dest);
        }
    }
    // closes the file
    infile2.close();
    return g;
}

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
