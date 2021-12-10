#include "Graph.h"
#include "forceDirected.h"
#include "cs225/PNG.h"
#include <vector>
#include <map>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <utility>

using namespace std;

map<string, pair<int,int>> GraphVisualization::initialLayout(Graph* g) {
    // set up a blank PNG as output

    unsigned int height = g->getNumV() * 5;

    cs225::PNG* output = new cs225::PNG(height, height);
    //make a vertex list 
    vector<Vertex*> vertices = g->getVertices();
   
    // go through the vertices and add them to the map.  
    for (Vertex* v : vertices) {
        if (positions.empty()) {
            vector<int> inputs;
            int x = rand() % output->width() - 10;
            int y = rand() % output->height() - 10;
            positions.insert({v->name_, make_pair(x,y)});
            // positions.insert({v.name_,inputs; });
        } else {
            pair<int,int> point = pickPoint(output);
            positions.insert({v->name_, point}); 

        }
    }

    return positions;
}

// makes sure the random points don't over lap or get too close. (give 5 px between them)
pair<int,int> GraphVisualization::pickPoint(cs225::PNG* output) {

    // set changing seed 
    srand(time(0));
    
    // pick a number but not on the peripheral
    int x = rand() % output->width() - 10;
    int y = rand() % output->height() - 10;

    // iterate through the map 
    for (auto const& [key, val] : positions) {
        if (val.first == x && val.second == y) {
            return pickPoint(output);
        } else {
            int dist = sqrt(pow(val.first - x, 2) + pow(val.second - y, 2));
            if (dist < 15) {
                return pickPoint(output);
            }
            
        }
    }

    return make_pair(x,y);  
    

}


cs225::PNG* GraphVisualization::drawGraph(map<string, pair<int, int>> layout) {
   
}



map<string, pair<int, int>> GraphVisualization::constructForceDirectedGraph(map<string, pair<int, int>> layout, Graph* g,
                                                             int maxIter, int length, float cooling, cs225::PNG* output) {
    unsigned int i = 1;
    vector<Vertex*> vertices = g->getVertices();
    int area = output->width() * output->height();
    float k = sqrt(area / vertices.size());

    float sumXa = 0;
    float sumYa = 0; 
    float sumXr = 0;
    float sumYr = 0;

    map<string, pair<float, float>> forces;
    map<string, pair<int, int>> forceLayout;

    while (i < maxIter && cooling > 0) {
        for (Vertex* u : vertices) {
            // double force on v = "sum of all repulsive forces" + "sum of attractive forces from adjacent vertices"

            // calculate attractive forces for all adjacent vertices 
            vector<Vertex*> adjacent = u->adjacent;
           
            for (Vertex* e : adjacent) {
                float dist = sqrt(pow(layout[u->name_].first - layout[e->name_].first, 2) 
                                + pow(layout[u->name_].second - layout[e->name_].second, 2));
                // calculate unit vector
                float x = layout[e->name_].first - layout[u->name_].first;
                float y = layout[e->name_].second - layout[u->name_].second;
                float magnitude = sqrt(pow(x,2) + pow(y,2));
                x = x / magnitude;
                y = y / magnitude;
                // calculate attractive force vector for this vertice and then add it to the total.
                float c = pow(dist, 2)/ length;
                sumXa = sumXa + (x * c);
                sumYa = sumYa + (y * c);

            }

            // calculate all repulsive forces
            for (Vertex* v : vertices) {
                if (v->name_ == u ->name_) {
                    continue;
                }
                float dist = sqrt(pow(layout[u->name_].first - layout[v->name_].first, 2) 
                                + pow(layout[u->name_].second - layout[v->name_].second, 2));
                 // calculate unit vector
                float x = layout[u->name_].first - layout[v->name_].first; // x + v = u 
                float y = layout[u->name_].second - layout[v->name_].second;
                float magnitude = sqrt(pow(x,2) + pow(y,2));
                x = x / magnitude;
                y = y / magnitude;

                float c = pow(length, 2) / dist;
                sumXr = sumXr + (x * c);
                sumYr = sumYr + (y * c);   
            }
            
            float forceX = sumXr + sumXa;
            float forceY = sumYr + sumYa;

            forces.insert({u->name_, make_pair(forceX, forceY)});
        }
         
        // 
        
        for (auto const& [key, val] : forces) {
            cooling = pow(cooling, i);
            int x = layout[key].first + (val.first * cooling);
            int y = layout[key].second + (val.second * cooling);
            forceLayout.insert({key, make_pair(x,y)});
        }

        i++;
    }
    return forceLayout;
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