#include "Graph.h"

#include <cstdio>
#include <vector>
#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include <iostream>
#include <string> 
#include <sstream> 

using std::string;
using std::vector;
using std::ifstream;
using namespace std;

void ConstructGraph(const string& filename, const string& filename2) {
    // Construct graph
    vector<Vertex> vertices;
    string line;
    //read in the file with all of the vertex names, the index of the vertex name in the vector is the vertex number it is in the adjacency matrix
    ifstream infile (filename);
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // push all of the vertices
            vector<string> v;
            const char delim = ' '; 
            std::vector<std::string> out; 
            std::stringstream ss(line); 
            std::string s;
            while (std::getline(ss, s, delim)) { 
                out.push_back(s); 
            } 
            for (auto &s: out) { 
                v.push_back(s);
            } 
            vertices.push_back(Vertex(v[1], v[0]));
        }
    }
    infile.close();
    Graph* g = createVertices(vertices.size());
    
    ifstream infile2(filename2);
    if (infile2.is_open()) {
        while (getline(infile2, line)) {
            // push all of the vertices
            vector<string> v;
            const char delim = ' '; 
            std::vector<std::string> out; 
            std::stringstream ss(line); 
            std::string s;
            while (std::getline(ss, s, delim)) { 
                out.push_back(s); 
            } 
            for (auto &s: out) { 
                v.push_back(s);
            } 
            int src;
            int dest;
            stringstream first(v[0]);
            stringstream second(v[1]);
            first >> src;
            second >> dest;
            addEdge(g, src, dest);
        }
    }
    infile2.close();
}