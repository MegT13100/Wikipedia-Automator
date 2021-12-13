#pragma once

#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>

using namespace std;

class GraphVisualization {
    public:
        /**
         * @brief This is an implementation of the Fructerman-Reingold force-directed graph algorithm. The algorithm images a situation
         *         where the vertices of a graph are connected by springs, and to find the best layout is to minimize the forces 
         *         between the springs so they sit at an optimal length apart. We want our vertices to be fairly evenly spaced, but 
         *         for adjacent vertices to be closer to each other, while non-adjacent vertices are far apart. 
         * @param layout the initial layout of the points in two dimensional space. In our implementation, 
         *                 the graph vertices are usually randomized. The layout maps the names of the vertices to the coordinates (x,y)
         * @param g the graph to be visualized and optimized
         * @param maxIter the maximum number of iterations to construct the graph
         * @param length the optimal edge length between vertices
         * @param cooling this is the cooling factor. As the algorithm keeps iterating, it theorhetically gets closer 
         *                 and closer to the optimal node distribution. Thus this dampens the forces moving the points so the points move 
         *                 less each iteration
         * @return map<string, pair<int, int>> : a map between the vertex names and the new positions 
         */
        map<string, pair<int, int>> constructForceDirectedGraph(map<string, pair<int, int>> layout, Graph* g,
                                                int maxIter, int length, float cooling);
        /**
         * @brief Sets up an initial, randomized layout for all of the vertices in the graph.
         * 
         * @param g Graph to be visualized. 
         * @return map<string, pair<int,int>> Returns a map of vertex names and coordinates (x,y)
         */
        map<string, pair<int,int>> initialLayout(Graph* g);
        /**
         * @brief Get the Positions object
         * 
         * @return map<string, pair<int,int>> 
         */
        map<string, pair<int,int>> getPositions();

        /**
         * @brief Draws the graph layout onto a PNG, in order to be written into a visual file.
         * 
         * @param layout The map of vertex coordinates used to visualize the graph
         * @return cs225::PNG* 
         */
        cs225::PNG* drawGraph(map<string, pair<int, int>> layout);
    private:
        /**
         * @brief This is a helper function to determine the initial layout. It is meant to find valid x and y values for each point 
         *         such that each point does not overlap (each point has a radius of 5px) and that they are not less that 5px apart. 
         *         Also they should be a sufficient distance from the edge of the png. 
         * 
         * @param output the PNG display of the graph (used to get the width and height to determine the boundaries)
         * @return pair<int,int> a point (x,y)
         */
        pair<int,int> pickPoint(cs225::PNG* output);
        /**
         * @brief map that holds the initial randomized positions for each vertex in the graph. Maps the names of the
         *        vertices to (x,y) coordinates 
         */
        map<string, pair<int,int>> positions;
        /**
         * @brief a PNG that holds a visualization of the graph
         */
        cs225::PNG * output;
};