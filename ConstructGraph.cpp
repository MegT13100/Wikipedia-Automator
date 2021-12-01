#include "Graph.h"

#include <cstdio>
#include <vector>
#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;
using namespace std;

void ConstructGraph(const string& filename, const string& filename2) {
    // Construct graph
    vector<string> vertices;
    string line;
    //read in the file with all of the vertex names, the index of the vertex name in the vector is the vertex number it is in the adjacency matrix
    ifstream infile (filename);
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // push all of the vertices
            vertices.push_back(line);
        }
    }
    infile.close();

    Graph* g = createVertices(count);
}