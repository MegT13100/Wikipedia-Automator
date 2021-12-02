#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("Fake data vertices added correctly", "[weight=1]") {
  Graph* g = constructGraph("fake_data_v.txt", "fake_data_e.txt");
  vector<string> v = {"animals", "dog", "cat", "wolf", "cat", "food", "soup", "mac and cheese"};
  for(int n = 0; n < (int) g->vertices.size(); n++) {
    REQUIRE(v[n] == g->vertices[n].name_);
    cout << v[n] << " " << g->vertices[n].name_ <<  endl;
  }
}

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