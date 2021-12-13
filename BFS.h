#pragma once

#include "Graph.h"
#include <map>
#include <queue>

/**
 * @brief class for performing a BFS traversal and shortest path algorithm on our data
 */
class BFS {
    public:
        /**
         * @brief constructor of BFS class, performs the traversal on the graph
         * @param the graph to traverse
         */
        BFS(Graph * g);
        /**
         * @brief helper function for traversing the graph
         * @param g graph to traverse 
         * @param v vertex to begin the traversal on
         */
        void traverse(Graph * g, Vertex * v);
        /**
         * @brief constructor of BFS class, performs the traversal on the graph
         * @param g the graph to traverse
         * @param v1 name of first vertex
         * @param v2 name of second vertex
         * @return string of the names of vertices creating the shortest path
         */
        string shortestPath(Graph * g, string v1, string v2);
    private:
        map<Vertex, bool> visited_;
};