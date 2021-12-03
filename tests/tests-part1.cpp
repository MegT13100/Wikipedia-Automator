#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../BFS.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("Fake data vertices added correctly", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  vector<string> v = {"animals", "dog", "cat", "wolf", "cow", "food", "soup", "mac and cheese"};
  for(int n = 0; n < (int) v.size(); n++) {
    REQUIRE(v[n] == g->getVertices()[n]->name_);
  }
}

/*TEST_CASE("Fake data edges added correctly", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  vector<string> v = {"animals", "dog", "cat", "wolf", "cow", "food", "soup", "mac and cheese"};
  for(int n = 0; n < (int) v.size(); n++) {
    REQUIRE(e[n] == g->edges[n]);
  }
}*/

TEST_CASE("contains edge is correct", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  REQUIRE( containsEdge(g, 0, 1) == true);
  REQUIRE( containsEdge(g, 6, 5) == true);
  REQUIRE( containsEdge(g, 3, 0) == true);
  REQUIRE( containsEdge(g, 7, 7) == true);
  REQUIRE( containsEdge(g, 0, 4) == false);
  REQUIRE( containsEdge(g, 5, 3) == false);
  REQUIRE( containsEdge(g, 7, 6) == false);
  REQUIRE( containsEdge(g, 8, 6) == false);
}

/*TEST_CASE("Adjacency matrix is correct", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  bool** answer = new bool[8][8]
    {
      {true, true, true, true, false, false, false, false}, 
      {true, true, false, true, false, false, false, false}, 
      {true, false, true, false, false, false, false, false}, 
      {true, true, false, true, false, false, false, false}, 
      {false, false, false, false, true, true, false, false},
      {false, false, false, false, true, true, true, true}, 
      {false, false, false, false, false, true, true, false}, 
      {false, false, false, false, false, true, false, true}
    };
  REQUIRE(answer == g->adjMatrix);
  delete answer;
}*/

TEST_CASE("shortest path parent", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  BFS b(g);
  b.traverse(g, g->getVertices()[0]);
  string solution = b.shortestPath(g, "cat", "cat");
  REQUIRE(solution == " animals cat");
}

TEST_CASE("shortest path same input", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  BFS b(g);
  b.traverse(g, g->getVertices()[0]);
  string solution = b.shortestPath(g, "cat", "cat");
  REQUIRE(solution == " cat");
}

TEST_CASE("shortest path same branch", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  BFS b(g);
  //b.traverse(g, g->getVertices()[0]);
  string solution = b.shortestPath(g, "cow", "mac and cheese");
  REQUIRE(solution == " cow food mac and cheese");
}

TEST_CASE("shortest path different branches", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  BFS b(g);
  b.traverse(g, g->getVertices()[2]);
  string solution = b.shortestPath(g, "cat", "mac and cheese");
  REQUIRE(solution == " cat animals cow food mac and cheese");
}