#include <cstdio>
#include <vector>
#include "Graph.h"

using namespace std;
int main() {
   //building the graph from the wikipedia files
   cout << "main runs" << endl;
   Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
   printGraph(g);
}