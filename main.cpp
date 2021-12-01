#include <cstdio>
#include <vector>
#include "Graph.h"

using namespace std;
int main() {
   //building the graph from the wikipedia files
   Graph g;
   g.ConstructGraph("data/wiki-topcats-page-names.txt", "data/wiki-topcats.txt");
}