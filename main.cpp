#include <cstdio>
#include <vector>
#include "Graph.h"
#include "BFS.h"
#include "forceDirected.h"
#include <string>

//to run main run ./graph
//possible visualizations: https://libcinder.org/
//create md file with progress updates

using namespace std;
int main() {
<<<<<<< HEAD
   //building the graph from the fake files
   cout << "main runs" << endl;
   //the first file should be sorted by index!
   //preprocess the data (only part of the dataset)
   //pre-filter
   //change to adjList
   Graph* g = constructGraph("data/wiki-topcats-page-names.txt", "data/wiki-topcats.txt"); //NO <3
   //Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt", 10);
=======
   cout << "main running" << endl;
   //Graph* g = constructGraph("data/wiki-topcats-page-names.txt", "data/wiki-topcats.txt", 3);
   //Graph* g = constructGraph("data/fake_data_v.txt", "data/fake_data_e.txt", 10);
   Graph* g = constructGraph("data/wiki-v.txt", "data/wiki-e.txt", 300);
   cout << "graph constructed . . ." << endl;
>>>>>>> 260158841ed06f53dd4061c04443cc7fed8d5393
   GraphVisualization v;
   cout << "graph visualization created . . ." << endl;
   //BFS b(g);
   //b.traverse(g, g->getVertices()[2]);
   //string solution = b.shortestPath(g, "Arkansas Highway 99", "Lower Parker School");
   map<string, pair<int, int>> layout = v.initialLayout(g);
   cs225::PNG * png = v.drawGraph(layout);
   png->writeToFile("graph.png");
   cout << "initial layout exported . . ." << endl;
   map<string, pair<int, int>> newMap = v.constructForceDirectedGraph(layout, g, 30, 101, 1);
   cs225::PNG * png2 = v.drawGraph(newMap);
   png2->writeToFile("forceDirectedGraph.png");
   cout << "force directed layout exported . . ." << endl;
   cout << "done" << endl;
   return 0;
}
