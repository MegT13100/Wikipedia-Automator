#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct Vertex {
        Vertex() {
                name_ = "";
                index_ = -1;
                parent_ = -1;
                distance_ = 0;
                
        }

        Vertex(string name, int index) {
                name_ = name;
                index_ = index;
                parent_ = -1;
                distance_ = 0;
        }

        string name_;
        int index_;
        int parent_;
        int distance_;
        vector<Vertex*> adjacent;
        string label;
};

struct Edge {
        Edge() {
                u = Vertex();
                v = Vertex();
        }

        Edge(Vertex u, Vertex v) {
                this->u = u;
                this->v = v;
        }

        Vertex u;
        Vertex v;
        string label;
};

class Graph {
        public:
                Graph();

                bool containsEdge(Graph const * const g, int src, int dest);

                void addEdge(Graph* g, int src, int dest);

                /*int numOutgoingEdges(Graph const * const g, int v);

                int numIncomingEdges(Graph const * const g, int v);*/

                void printGraph(Graph const * const g);

                Graph* createVertices(int numV);

                Graph* constructGraph(const string& filename, const string& filename2);

                vector<Vertex*> getVertices() const;

                vector<Edge> getEdges() const;
        
        private:
                //map<Edge, bool>** adjMatrix;
                bool** adjMatrix;
                //number of vertices in the graph
                int n;
                //vector of all vertices
                vector<Vertex*> vertices;
                //vector of all edges
                vector<Edge> edgeList;
                //vector of all edges indexed by the verticies that it is a part of
                vector<vector<Edge>> edges;
                //map that contains all the adjacent edges for a given vertex
                //std::unordered_map<int, vector<Vertex>> adjacent;
};