
#include "catch.hpp"

#include "../Graph.h"

#include "../cs225/PNG.h"
using cs225::PNG;

#include "../cs225/HSLAPixel.h"
using cs225::HSLAPixel;

#include <vector>


TEST_CASE("Fake data edges added correctly", "[weight=1][graph]") {
  Graph* g = constructGraph("data/fake_data_v.txt", "data/fake_data_e.txt", 10);
  REQUIRE( containsEdge(g, 0, 1) == true);
  REQUIRE( containsEdge(g, 6, 5) == true);
  REQUIRE( containsEdge(g, 3, 0) == true);
  REQUIRE( containsEdge(g, 7, 7) == true);
  REQUIRE( containsEdge(g, 0, 4) == false);
  REQUIRE( containsEdge(g, 5, 3) == false);
  REQUIRE( containsEdge(g, 7, 6) == false);
}

TEST_CASE("Fake data vertices added correctly", "[weight=1][graph]") {
  Graph* g = constructGraph("data/fake_data_v.txt", "data/fake_data_e.txt", 10);
  vector<string> v = {"animals", "dog", "cat", "wolf", "cow", "food", "soup", "mac and cheese"};
  for(int n = 0; n < (int) v.size(); n++) {
    REQUIRE(v[n] == g->getVertices()[n]->name_);
  }
}

TEST_CASE("contains edge is correct", "[weight=1][graph]") {
  Graph* g = constructGraph("data/fake_data_v.txt", "data/fake_data_e.txt", 10);
  REQUIRE( containsEdge(g, 0, 1) == true);
  REQUIRE( containsEdge(g, 6, 5) == true);
  REQUIRE( containsEdge(g, 3, 0) == true);
  REQUIRE( containsEdge(g, 7, 7) == true);
  REQUIRE( containsEdge(g, 0, 4) == false);
  REQUIRE( containsEdge(g, 5, 3) == false);
  REQUIRE( containsEdge(g, 7, 6) == false);
  REQUIRE( containsEdge(g, 8, 6) == false);
}
