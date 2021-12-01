#include <cstdio>
#include <vector>

#include "Graph.h"

using namespace std;

void ConstructGraph() {
    // Construct graph
    Graph* g = createVertices(3);
    addEdge(g, 0, 1);
    addEdge(g, 1, 0);
    addEdge(g, 2, 1);
}