#include "Graph.h"

/* we have a list of edges 
we want to randomly place nodes and we want to push the nodes away from each other into a configuration where they: 

1. Vertices connected by an edge should be drawn near each other.
2. Vertices should not be drawn too close to each other.

make the algorithm small first - we should create a sample txt file and output file. and then scale up on our graph
maybe make one with 10 nodes, then 100 nodes. 

their algorithm goes through iterations
use an adjancency list it seems simpler? 
put initial positions into a 1x1 square
 
 * might be cool if we colored on category? 

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
        each vertex has two 
    }

*/

 
