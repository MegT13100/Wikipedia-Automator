#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../BFS.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../PageRank.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("Test FindPageRanks()", "[pagerank][1]") {
    // make graph
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    vector<double> correct_vector;

    // set this to the correct answer and then run the actual method
    // 0.1275, 0.1275, 0.1275, 0.1275, 0.1275, 0.1275, 0.1275
    correct_vector.push_back(0.1444228752);
    correct_vector.push_back(0.2298858405);
    correct_vector.push_back(0.2298858405);
    correct_vector.push_back(0.3958054439);

    // run actual pagerank method
    PageRank page_rank(g);
    vector<double> vector_from_method = page_rank.FindPageRanks(0.85, 5);

    std::cout << vector_from_method.size() << std::endl;

    for (unsigned i = 0; i < correct_vector.size(); i++) { 
        double scale = 0.1;
        correct_vector[i] = (int)(correct_vector[i] / scale) * scale;
        vector_from_method[i] = (int)(vector_from_method[i] / scale) * scale;
        REQUIRE(correct_vector[i] == vector_from_method[i]);
    }
}

TEST_CASE("Test GetInboundLinks()", "[pagerank][2]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    PageRank page_rank(g);
    map<int, vector<int>> correct_inbound_links;
    //mymap.insert ( std::pair<char,int>('a',100) );

    std::vector<int> v1{1};
    std::vector<int> v2{0, 3};
    std::vector<int> v3{0, 3};
    std::vector<int> v4{0, 1, 2};

    correct_inbound_links.insert(std::pair<int, vector<int>>(0, v1));
    correct_inbound_links.insert(std::pair<int, vector<int>>(1, v2));
    correct_inbound_links.insert(std::pair<int, vector<int>>(2, v3));
    correct_inbound_links.insert(std::pair<int, vector<int>>(3, v4));

    map<int, vector<int>> inbound_links = page_rank.GetInboundLinks();

    REQUIRE(correct_inbound_links == inbound_links);
}

TEST_CASE("Test MakeMaze", "[pagerank][3]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    PageRank page_rank(g);
    vector<double> vector_from_method = page_rank.FindPageRanks(0.85, 5);

    page_rank.PrintPageRanks(vector_from_method);
}