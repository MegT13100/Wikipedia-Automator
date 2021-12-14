#pragma once

#include "Graph.h"
#include <map>

/**
 * The PageRank algorithm measures the importance of the Wikipedia links,
 * which are represented by the vertices of the graph provided. The connections
 * between these links are formulated by edges between the vertices. By
 * utilizing the PageRank algorithm, we want to determine and visualize the rank of
 * importance for each Wikipedia links in this dataset.
 */
class PageRank {
    public:
        /**
         * Constructor which takes in a Graph
         * @param g the graph we are calculating the PageRanks on
          */
        PageRank(Graph* g);

        /**
         * Utilizes the PageRank iterative algorithm to provide PageRanks
         * of the vertices as a list (in order of the vertex indices)
         * @param d the damping factor (typically 0.85)
         * @param num_iterations the number of iterations
         */
        vector<double> FindPageRanks(double d, size_t num_iterations);

        /**
         * Maps a vertex A's index to a list of vertices (their indices)
         * that link to A for all vertices in the Graph
         */
        map<int, vector<int>> GetInboundLinks();

        /*
         * Creates a matrix representation for the probabilities of a Random Surfer Model.
         * Initially creates a N * N matrix which marks basic probabilities where there are
         * edges between vertices.
         * NOTE: the probabilities denote how likely a Surfer would click on a following link.
         */
        double** CreateMatrix();

    private:
        Graph* graph_;
};