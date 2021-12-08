#include "Graph.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <utility>

using namespace std;

map<string, vector<int>> GraphVisualization::initialLayout(Graph g) {
    // set up a blank PNG as output
    cs225::PNG* output = new cs225::PNG(g.getNumV * 5, g.getNumV * 5);
    //make a vertex list 
    vector<Vertex*> vertices = g.getVertices;
   
    // go through the vertices and add them to the map.  
    for (Vertex* v : vertices) {
        if (positions.empty()) {
            vector<int> inputs;
            int x = rand() % output->width_ - 10;
            int y = rand() % output->height_ - 10;
            inputs.push_back(x);
            inputs.push_back(y);
            positions.insert({v.name_,inputs; });
        } else {
            vector<int> point = pickPoint(output);
            positions.insert({v.name_, point}) 

        }
    }

    return positions;
}

// makes sure the random points don't over lap or get too close. (give 5 px between them)
vector<int> GraphVisualization::pickPoint(cs225::PNG* output) {

    vector<int> final;

    // set changing seed 
    srand(time(0));
    
    // pick a number but not on the peripheral
    int x = rand() % output->width_ - 10;
    int y = rand() % output->height_ - 10;


    for (string name : position) {
        if (position[name][0] == x && position[name][1] == y) {
            return pickPoint(output);
        } else {
            int dist = sqrt(pow(position[name][0] - x, 2) + pow(position[name][1] - y, 2));
            if (dist < 15) {
                return pickPoint(output);
            }
            
        }
    }

    final.push_back(x);
    final.push_back(y);
    
    return final;  
    

}


cs225::PNG* GraphVisualization::drawGraph(map<string, pair<int, int>> layout) {
    return PNG();
}




cs225::PNG GraphVisualization::drawForceDirectedGraph(map<string, pair<int, int>>, Graph g, double threshold, int maxIter) {
    i = 1;
    while (i < maxIter && "forces" > threshold) {
        for (Vertex* v : vertices) {
            // double force on v = "sum of all repulsive forces" + "sum of attractive forces from adjacent vertices"
        }
        for (Vertex* v : vertices) {
            // take position, apply force, which will move the position 
            // pair position = posiiton + (force * cooling factor) cooling factor goes from 1 - 0 exponentially
            // or cooling can be always 1 (though we want it to be like 0.99)
        }
        i++;
    }
}

// repulsive forces: 
/*
crep (repulsion constant) = 2.0 "in fruct-rein this is L^2" / (euclidean distance between u & v)  * direction from v to u (unit vector)
*/
// attractive forces:
/*
cspring (spring constnant) = 1.0 * log 10 (abs(dist between u & v) / L or the ideal length of spring edges) * unit vector from u to v
f attract = spring force - repulsive force

f attract = dist^2 / L  * unit vec from u to v for FR you need a larger length if you have a smaller cooling factor and vice versa
*/

// ⟨→BA⟩=(2,3)−(−3,2)=⟨5,1⟩
// A = (2,3) and B = (-3,2)
// subtract start from the terminal point so 
// 2 --3 = 5 and 3 - 2 = 1 
// so v1 