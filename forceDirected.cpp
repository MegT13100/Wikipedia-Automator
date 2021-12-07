#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>
#include <time.h>
#include <cmath>
#include <cstdlib>

/* we have a list of edges 
we want to randomly place nodes and we want to push the nodes away from each other into a configuration where they: 

1. Vertices connected by an edge should be drawn near each other.
2. Vertices should not be drawn too close to each other.

make the algorithm small first - we should create a sample txt file and output file. and then scale up on our graph
maybe make one with 10 nodes, then 100 nodes. 

their algorithm goes through iterations
use an adjancency list it seems simpler? 
put initial positions into a 1x1 square


*/

/*
pseudocode:

to begin, we need:
area = (w*l);
the graph
k = sqrt(area/|V|); // the optimal distance btw nodes

for i in # of iterations: 
    (calculate repulsive forces )
    for v : vertices {
        (each vertex has two vectors: .pos and .disp?)
        v.disp = 0;
        for u in
    }

*/


cs225::PNG* drawGraph::drawGraph(Graph g) {
    // set up a blank PNG as output
    cs225::PNG* output = new cs225::PNG(numV * 5, numV * 5);
    //make a vertex list 
    vector<Vertex*> vertices = g.getVertices;
    // set changing seed 
    srand(time(0));
    // go through the vertices and add them to the map. draw circles where all of the vertices will be (5px radius). 
    // no two vertices should overlap. or be closer than  
    for (Vertex* v : vertices) {
        int x = rand() % output->width_;
        int y = rand() % output->height;

        cs225::HSLAPixel & pixel = output->getPixel(x, y);
        // draw all of the circles afterwards, set up all of the vertices. 
        int dist = pow(x, 2) + pow(y, 2);
        dist = sqrt(dist);
        // use the distance from the point to make all of your calculations. 
        // set random drawing and then work on force-directed. 
    }

    return PNG();

}

void drawGraph::drawCircle(cs225::PNG* points){

}

double drawGraph::calculateEdge() {
    return 0.0;
}
