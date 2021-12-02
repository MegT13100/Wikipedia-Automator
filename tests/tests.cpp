#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../Graph.h"

#include "../cs225/PNG.h"
using cs225::PNG;

#include "../cs225/HSLAPixel.h"
using cs225::HSLAPixel;

#include <vector>


/*TEST_CASE("Fake data vertices added correctly", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  REQUIRE( ...);
}*/

TEST_CASE("Fake data edges added correctly", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  REQUIRE( containsEdge(g, 0, 1) == true);
  REQUIRE( containsEdge(g, 6, 5) == true);
  REQUIRE( containsEdge(g, 3, 0) == true);
  REQUIRE( containsEdge(g, 7, 7) == true);
  REQUIRE( containsEdge(g, 0, 4) == false);
  REQUIRE( containsEdge(g, 5, 3) == false);
  REQUIRE( containsEdge(g, 7, 6) == false);
}

/*TEST_CASE("Adjacency matrix prints correctly", "[weight=1]") {
    Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  REQUIRE( ...);
}*/