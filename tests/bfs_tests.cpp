#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../BFS.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("shortest path parent", "[weight=1][BFS]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt", 10);
  BFS b(g);
  b.traverse(g, g->getVertices()[0]);
  string solution = b.shortestPath(g, "animals", "cat");
  REQUIRE(solution == " animals cat");
}

TEST_CASE("shortest path same input", "[weight=1][BFS]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt", 10);
  BFS b(g);
  b.traverse(g, g->getVertices()[0]);
  string solution = b.shortestPath(g, "cat", "cat");
  REQUIRE(solution == " cat");
}

TEST_CASE("shortest path same branch", "[weight=1][BFS]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt", 10);
  BFS b(g);
  string solution = b.shortestPath(g, "cow", "mac and cheese");
  REQUIRE(solution == " cow food mac and cheese");
}

TEST_CASE("shortest path different branches", "[weight=1][BFS]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt", 10);
  BFS b(g);
  b.traverse(g, g->getVertices()[2]);
  string solution = b.shortestPath(g, "cat", "mac and cheese");
  REQUIRE(solution == " cat animals cow food mac and cheese");
}