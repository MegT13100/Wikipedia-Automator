#include <cstdio>
#include <vector>
#include "Graph.h"
#include "BFS.h"

//to run main run ./graph


using namespace std;
int main() {
   //building the graph from the fake files
   cout << "main runs" << endl;
   //the first file should be sorted by index!
   Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
   printGraph(g);
   BFS b(g);
   b.traverse(g, g->vertices[2]);
   //cout << g->vertices.size() << endl;
   //cout << g->vertices[0].name_ << endl;
   //cout << g->vertices[2].parent_ << endl;
   vector<string> solution = b.shortestPath(g, "cat", "mac and cheese");

   for(int i = 0; i < (int) solution.size(); i++) {
      cout << solution[i];
   }
   cout << endl;
}