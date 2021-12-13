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
   //building the graph from the fake files
   cout << "main runs" << endl;
   //the first file should be sorted by index!
   //preprocess the data (only part of the dataset)
   //pre-filter
   //change to adjList
   Graph* g = constructGraph("data/wiki-topcats-page-names.txt", "data/wiki-topcats.txt", 500);
   //Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt", 10);
   GraphVisualization v;
   //printGraph(g);
   //FS b(g);
   //b.traverse(g, g->getVertices()[2]);
   //string solution = b.shortestPath(g, "Arkansas Highway 99", "Lower Parker School");
   //cout << solution << endl;
   map<string, pair<int, int>> layout = v.initialLayout(g);
   cs225::PNG * png = v.drawGraph(layout);
   png->writeToFile("graph.png");
   // cout << layout.size() << endl;
   // for(auto it : layout) {
   //    cout << "hello" << endl;
   //    cout << it.first << " " << it.second.first << " " << it.second.second << endl;
   // }
   //cout << "force directed run" << endl;
   //cout << "output width: " << v.output->width() << endl;
   map<string, pair<int, int>> newMap = v.constructForceDirectedGraph(layout, g, 30, 101, 1);
   cs225::PNG * png2 = v.drawGraph(newMap);
   png2->writeToFile("forceDirectedGraph.png");
   cout << "done" << endl;
   /*for(auto it : newMap) {
      cout << it.first << " " << it.second.first << " " << it.second.second << endl;
   }*/
   return 0;
}
