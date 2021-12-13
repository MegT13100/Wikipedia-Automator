#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../BFS.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../PageRank.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("Constructs Matrix Correctly", "[pagerank][1]") {
    Graph* g = constructGraph("test_data2_pagerank.txt", "test_data2_pagerank.txt", 100);
    int num_v = g->getNumV();
    double **correct_matrix = new double*[num_v];

    // set this to the correct answer and then run the actual method
    // diagonal is 0
    correct_matrix[0] = new double[num_v];
    correct_matrix[1] = new double[num_v];
    correct_matrix[2] = new double[num_v];
    correct_matrix[3] = new double[num_v];

    correct_matrix[0][0] = 0;
    correct_matrix[0][1] = 0.5;
    correct_matrix[0][2] = 0;
    correct_matrix[0][3] = 0;

    correct_matrix[1][0] = 0.33;
    correct_matrix[1][1] = 0;
    correct_matrix[1][2] = 0;
    correct_matrix[1][3] = 0.5;

    correct_matrix[2][0] = 0.33;
    correct_matrix[2][1] = 0;
    correct_matrix[2][2] = 0;
    correct_matrix[2][3] = 0.5;

    correct_matrix[3][0] = 0.33;
    correct_matrix[3][1] = 0.5;
    correct_matrix[3][2] = 1;
    correct_matrix[3][3] = 0;

    // run actual pagerank method
    PageRank page_rank(g);
    double** matrix_from_method = page_rank.CreateMatrix();

    for (int i = 0; i < num_v; i++) {
        for (int j = 0; j < num_v; j++) {
            REQUIRE(correct_matrix[i][j] == matrix_from_method[i][j]);
        }
    }
}

TEST_CASE("Constructs Matrix Correctly Part 2", "[pagerank]") {
    Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt", 100);
    int num_v = g->getNumV();
    double **correct_matrix = new double*[num_v];
    // set this to the correct answer and then run the actual method

    // run actual pagerank method
    PageRank page_rank(g);
    double** matrix_from_method = page_rank.CreateMatrix();

    for (int i = 0; i < num_v; i++) {
        for (int j = 0; j < num_v; j++) {
            REQUIRE(correct_matrix[i][j] == matrix_from_method[i][j]);
        }
    }
}

TEST_CASE("Test Columns Add to 1", "[pagerank]") {

}

TEST_CASE("Test Columns Add to 1 Part 2", "[pagerank]") {

}

TEST_CASE("Test FindPageRanks()", "[pagerank]") {
    Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt", 100);
    vector<double> correct_vector;
    // set this to the correct answer and then run the actual method

    // run actual pagerank method
    PageRank page_rank(g);
    vector<double> vector_from_method= page_rank.FindPageRanks(0.85, 5); //damping factor is 0.85 typically

    REQUIRE(correct_vector == vector_from_method);
}

TEST_CASE("Test FindPageRanks() Part 2", "[pagerank][4]") {
    // make graph
    Graph* g = constructGraph("test_data2_pagerank.txt", "test_data2_pagerank.txt", 100);
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

TEST_CASE("Test getInboundLinks()", "[pagerank]") {
    //Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt");
}

TEST_CASE("Test getInboundLinks() Part 2", "[pagerank]") {
    //Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt");
}

TEST_CASE("Test PowerMethod", "[pagerank]") {
    //Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt");
}

TEST_CASE("Test PowerMethod Part 2", "[pagerank]") {
    //Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt");
}

TEST_CASE("Test pagerank on small dataset", "[pagerank]") {
    //Graph* g = constructGraph("test_data_pagerank.txt", "test_data_pagerank.txt");
}