#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
/**
 * @brief structure to hold the vertices of the graph
 */
struct Vertex {
        Vertex() {
                name_ = "";
                index_ = -1;
                parent_ = -1;
                distance_ = 0;
                degree_ = 0;   
                label = "UNEXPLORED";
        }

        Vertex(string name, int index) {
                name_ = name;
                index_ = index;
                parent_ = -1;
                distance_ = 0;
                degree_ = 0;
                label = "UNEXPLORED";
        }

        string name_;
        int index_;
        int parent_;
        int distance_;
        vector<Vertex*> adjacent;
        string label;
        int degree_;
};
/**
 * @brief structure to hold the edges of the graph
 */
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
/**
 * @brief class to hold the graph
 */
class Graph {
        public:
                /*Graph();
                Graph(string name1, string name2);*/
                bool** adjMatrix;
                //bool** getAdjMatrix() const;
                //void setAdjMatrix(bool** am);
                vector<Vertex*> getVertices() const;
                void setVertices(vector<Vertex*> vs);
                vector<Edge*> getEdgeList() const;
                vector<vector<Edge*>> getEdges() const;
                void setEdges(vector<vector<Edge*>> edgs);
                int getNumV() const;
                void setNumV(int n_);
        
        private:
                //Graph * g;
                //map<Edge, bool>** adjMatrix;
                //number of vertices in the graph
                int numV;
                //vector of all vertices
                vector<Vertex*> vertices;
                //vector of all edges
                vector<Edge*> edgeList;
                //vector of all edges indexed by the verticies that it is a part of
                vector<vector<Edge*>> edges;
                //map that contains all the adjacent edges for a given vertex
                //std::unordered_map<int, vector<Vertex>> adjacent;
};
        /**
         * @brief creates an empty graph with the given number of vertices
         * @param numV number of vertices
         * @return pointer to a graph object
         */
        Graph* createVertices(int numV);
<<<<<<< HEAD

        Graph* constructGraph(const string& filename, const string& filename2); // no third parameter

=======
        /**
         * @brief creates a graph from two data files: one with the vertices and the second with the edges
         * @param filename file with vertices formatted 0 Vertex Name
         * @param filename2 file with edges formatted 0 100
         * @param numData number of datapoints from the file that should be read in 
         * @return pointer to a graph object
         */
        Graph* constructGraph(const string& filename, const string& filename2, int numData);
        /**
         * @brief adds an edge to the graph
         * @param g pointer to the graph where edges will be added
         * @param src index of the source vertex for the edge
         * @param dest index of the destination vertex for the edge
         */
>>>>>>> 260158841ed06f53dd4061c04443cc7fed8d5393
        void addEdge(Graph* g, int src, int dest);
        /**
         * @brief searches the adjacency matrix to see if the edge exists
         * @param g pointer to the graph to search
         * @param src index of the source vertex for the edge
         * @param dest index of the destination vertex for the edge
         * @return if the edge exists or not
         */
        bool containsEdge(Graph const * const g, int src, int dest);
        /**
         * @brief print the adjacency matrix associated with the given graph
         * @param g pointer to the graph to print
         */
        void printGraph(Graph const * const g);