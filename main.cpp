#include <cstdio>
#include <vector>
#include "Graph.h"
#include "BFS.h"

//to run main run ./graph
//possible visualizations: https://libcinder.org/
//create md file with progress updates

using namespace std;
int main() {
   //building the graph from the fake files
   cout << "main runs" << endl;
   //the first file should be sorted by index!
   //preprocess the data (only part of the dataset)
   //pre-filter
   //change to adjList
   //Graph* g = constructGraph("data/wiki-topcats-page-names.txt", "data/wiki-topcats.txt");
   Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
   printGraph(g);
   BFS b(g);
   b.traverse(g, g->getVertices()[2]);
   string solution = b.shortestPath(g, "cat", "mac and cheese");
   cout << solution << endl;
}