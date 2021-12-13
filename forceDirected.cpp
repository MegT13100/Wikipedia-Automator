#include "Graph.h"
#include "forceDirected.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <chrono>
#include <random>
#include <cstdlib>

using namespace std;

/**
 * @brief Sets up an initial, randomized layout for all of the vertices in the graph.
 * 
 * @param g Graph to be visualized. 
 * @return map<string, pair<int,int>> Returns a map of vertex names and coordinates (x,y)
 */

map<string, pair<int,int>> GraphVisualization::initialLayout(Graph* graph) {
    // set changing seed 
    //srand(time(0));
    g = graph;
    unsigned int height = g->getNumV() * 30;
    //cout<< height <<  endl;
    output = new cs225::PNG(height, height);
    //make a vertex list 
    vector<Vertex*> vertices = g->getVertices();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0, height - 5);
    //std::uniform_int_distribution<int> height(0, height - 5);
   
    // go through the vertices and add them to the map.  
    for (Vertex* v : vertices) {
        //if positions is empty, add a random coordinate
        //if (positions.empty()) {
            vector<int> inputs;
            unsigned int x = distribution(generator);
            unsigned int y = distribution(generator);
            positions.insert({v->name_, make_pair(x,y)});
            // positions.insert({v.name_,inputs; });
        //if positions isn't empty, pick a point
        /*} else {
            pair<int,int> point = pickPoint(output);
            positions[v->name_] = point;
        }*/
    }
    return positions;
}

/**
 * @brief This is a helper function to determine the initial layout. It is meant to find valid x and y values for each point 
 *         such that each point does not overlap (each point has a radius of 5px) and that they are not less that 5px apart. 
 *         Also they should be a sufficient distance from the edge of the png. 
 * 
 * @param output the PNG display of the graph (used to get the width and height to determine the boundaries)
 * @return pair<int,int> a point (x,y)
 */

pair<int,int> GraphVisualization::pickPoint(cs225::PNG* output) {
    // set changing seed 
   // srand(time(0));
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0, output->height() - 5);
    visited = positions;
    // pick numbers for the coordinate values that do not lieon the peripheral
    unsigned int x = distribution(generator);
    unsigned int y = distribution(generator);
    //cout << x << " " << y << endl;
    // iterate through the map (this syntax may be messed up)
    /*for (auto it : positions) {
        if (it.second.first == x && it.second.second == y) {
            return pickPoint(output);
        } else {
            int dist = sqrt(pow(it.second.first - x, 2) + pow(it.second.second - y, 2));
            if (dist < 15) {
                return pickPoint(output); 
            }
        }
    }*/
    return make_pair(x,y);  
}

/**
 * @brief Draws the graph layout onto a PNG, in order to be written into a visual file.
 * 
 * @param layout The map of vertex coordinates used to visualize the graph
 * @return cs225::PNG* 
 */

cs225::PNG* GraphVisualization::drawGraph(map<string, pair<int, int>> layout) {
    //draws vertices based on layout inputted
    cs225::PNG* png = new cs225::PNG(output->width(), output->height());
    for(unsigned int x = 0; x < output->width(); x++) {
        for(unsigned int y = 0; y < output->height(); y++) {
            for(auto it: layout) {
                double ox = it.second.first;
                double oy = it.second.second;
                double d = sqrt(pow((ox - x), 2) + pow((oy - y), 2));
                //make vertices into circle of radius 10 pixels
                if(abs(d) < 10) {
                    cs225::HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.l = 0;
                }
                
            }
        }
    }
    //add edges/lines based on adjacency list
    //for vertex in adjacency list, if the pixel is on the line ((y1 -y2) = m(x1 -x2)), make it black 
    for(auto v : g->getVertices()) {
        //coordinates of current vertex in layout
        int a = layout[v->name_].first;
        int b = layout[v->name_].second;
        for(auto v2 : v->adjacent) {
            //coordinates of adjacent vertex in layout
            int c = layout[v2->name_].first;
            int d = layout[v2->name_].second;
            int count = 0;
            for(int x = 0; x < (int) output->width(); x++) {
                for(int y = 0; y < (int) output->height(); y++) {
                    //all pixels on the line between the two points become black
                    if(abs((c-a)*(y-b)-(d -b)*(x-a)) < 500) {
                        //increments count when the first vertex is reached
                        if((x == a && y == b)) {
                            count++;
                        }
                        //increments count when the second vertex is reached
                        if((x == c && y == d)) {
                            count++;
                        }
                        //only draws the line when it is between the two vertices
                        if(count == 1) {
                            cs225::HSLAPixel & pixel2 = png->getPixel(x, y);
                            pixel2.l = 0;
                        }
                    }
                }
            }
        }
    }
    return png;
}
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

map<string, pair<int, int>> GraphVisualization::constructForceDirectedGraph(map<string, pair<int, int>> layout, Graph* g,
                                                             int maxIter, int length, float cooling) {
    vector<Vertex*> vertices = g->getVertices();
    /**
     * To calculate the forces, the x and y value of each vector have been split apart for ease of calculation. 
     * "a" is for attractive forces
     * "r" is for repulsive forces
     */
    float sumXa = 0;
    float sumYa = 0; 
    float sumXr = 0;
    float sumYr = 0;

    map<string, pair<float, float>> forces;
    map<string, pair<int, int>> forceLayout;

    // keep iterating until we've hit the maximum number of iterations, or the cooling factor hits 0
    for (int i = 1; i < maxIter && cooling > 0; i++) {
        for (Vertex* u : vertices) {
            // the total force to move u = "sum of all repulsive forces" + "sum of attractive forces from adjacent vertices"

            // calculate attractive forces for all adjacent vertices 
            vector<Vertex*> adjacent = u->adjacent;
           
            for (Vertex* e : adjacent) {
                float dist = sqrt(pow(layout[u->name_].first - layout[e->name_].first, 2) 
                                + pow(layout[u->name_].second - layout[e->name_].second, 2));
                // calculate unit vector from u to v
                float x = layout[e->name_].first - layout[u->name_].first;
                float y = layout[e->name_].second - layout[u->name_].second;
                float magnitude = sqrt(pow(x,2) + pow(y,2));
                x = x / magnitude;
                y = y / magnitude;
                // calculate attractive force vector for this vertex and then add it to the total.
                float c = pow(dist, 2)/ length;
                sumXa = sumXa + (x * c);
                sumYa = sumYa + (y * c);

            }

            // calculate repulsive forces for all vertices
            for (Vertex* v : vertices) {
                if (v->name_ == u ->name_) {
                    continue;
                }
                float dist = sqrt(pow(layout[u->name_].first - layout[v->name_].first, 2) 
                                + pow(layout[u->name_].second - layout[v->name_].second, 2));
                 // calculate unit vector from v to u
                float x = layout[u->name_].first - layout[v->name_].first; // x + v = u 
                float y = layout[u->name_].second - layout[v->name_].second;
                float magnitude = sqrt(pow(x,2) + pow(y,2));
                x = x / magnitude;
                y = y / magnitude;
                // calculate repulsive force vector for this vertex and then add it to the total.
                float c = pow(length, 2) / dist;
                sumXr = sumXr + (x * c);
                sumYr = sumYr + (y * c);   
            }
            //calculate total force on u, add it to a map of the forces on each vertex
            float forceX = sumXr + sumXa;
            float forceY = sumYr + sumYa;

            forces.insert({u->name_, make_pair(forceX, forceY)});
        }
         
        // calculate new position for each using forces and the cooling constant, add to a map of the new graph layout. 
        for (auto it: forces) {
            cooling = pow(cooling, i);
            int x = (int) (layout[it.first].first + (it.second.first * cooling)) % (int) output->width();
            int y =  (int) (layout[it.first].second + (it.second.second * cooling)) % (int) output->width();
            forceLayout[it.first] = make_pair(abs(x), abs(y));
        }
    }
    return forceLayout;
}

/**
 * @brief Getter for the initial positions mapping
 * 
 * @return map<string, pair<int,int>> Map of vertex names to (x,y) coordinates
 */

map<string, pair<int,int>> GraphVisualization::getPositions() {
    return positions;
}

