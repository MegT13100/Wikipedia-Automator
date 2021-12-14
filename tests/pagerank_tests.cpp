#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../BFS.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../PageRank.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("Test FindPageRanks()", "[pagerank][5]") {
    // make graph
    Graph* g = constructGraph("data/pr_data_v.txt.txt", "data/pr_data_e.txt", 100);
    vector<double> correct_vector;

    // set this to the correct answer and then run the actual method
    // 0.1275, 0.1275, 0.1275, 0.1275, 0.1275, 0.1275, 0.1275
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);

    // run actual pagerank method
    PageRank page_rank(g);
    vector<double> vector_from_method= page_rank.FindPageRanks(0.85, 5);

    for (unsigned i = 0; i < vector_from_method.size(); i++) {
        std::cout << "vector: " << vector_from_method[i] << std::endl;
    }

    REQUIRE(correct_vector == vector_from_method);
}

TEST_CASE("Test FindPageRanks() Part 2", "[pagerank][6]") {
    // make graph
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    vector<double> correct_vector;

    // set this to the correct answer and then run the actual method
    // 0.1275, 0.1275, 0.1275, 0.1275, 0.1275, 0.1275, 0.1275
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);
    correct_vector.push_back(0.1275);

    // run actual pagerank method
    PageRank page_rank(g);
    vector<double> vector_from_method= page_rank.FindPageRanks(0.85, 5);

    for (unsigned i = 0; i < vector_from_method.size(); i++) {
        std::cout << "vector: " << vector_from_method[i] << std::endl;
    }

    REQUIRE(correct_vector == vector_from_method);
}

TEST_CASE("Test GetInboundLinks()", "[pagerank][7]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    PageRank page_rank(g);
    map<int, vector<int>> correct_inbound_links;

    // for (auto pair : page_rank.GetInboundLinks()) {
    //     for (auto v_index : pair.second) {
    //     }
    // }

    REQUIRE(true == false);
}


TEST_CASE("Test getInboundLinks() Part 2", "[pagerank][8]") {
    //Graph* g = constructGraph("data/pr_data_v.txt.txt", "data/pr_data_v.txt.txt");
}

TEST_CASE("Test pagerank on small dataset", "[pagerank][11]") {
    //Graph* g = constructGraph("data/pr_data_v.txt.txt", "data/pr_data_v.txt.txt");
}

TEST_CASE("Test PrintPageRanks()", "[pagerank][12]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    PageRank page_rank(g);

    page_rank.PrintPageRanks(page_rank.FindPageRanks(0.85, 5));

    REQUIRE(true == false);
}