#include <cstdio>
#include <vector>
#include "Graph.h"
#include "BFS.h"
#include "forceDirected.h"
#include "PageRank.h"
#include <string>

//to run main run ./graph
//possible visualizations: https://libcinder.org/
//create md file with progress updates

using namespace std;
int main() {
   cout << "main running" << endl;
   
   Graph* g = constructGraph("data/fake_data_v.txt", "data/fake_data_e.txt", 10);
   cout << "graph constructed . . ." << endl

   // // PageRank
   PageRank page_rank(g);
   page_rank.PrintPageRanks(page_rank.FindPageRanks(0.85, 5000));

   // BFS
   BFS b(g);
   b.traverse(g, g->getVertices()[2]);
   string solution = b.shortestPath(g, "cat", "mac and cheese");
   cout << solution << endl;
   
   ;
   GraphVisualization v;
   cout << "graph visualization created . . ." << endl;

   // Visualize initial, randomized layout
   map<string, pair<int, int>> layout = v.initialLayout(g);
   cs225::PNG * png = v.drawGraph(layout);
   png->writeToFile("graph.png");
   cout << "initial layout exported . . ." << endl;

   //Visualize force-directed graph 
   map<string, pair<int, int>> newMap = v.constructForceDirectedGraph(layout, g, 30, 101, 1);
   cs225::PNG * png2 = v.drawGraph(newMap);
   png2->writeToFile("forceDirectedGraph.png");
   cout << "force directed layout exported . . ." << endl;

   cout << "done" << endl;
   return 0;
}
