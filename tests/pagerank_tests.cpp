#include "../cs225/catch/catch.hpp"

#include "../Graph.h"
#include "../BFS.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../PageRank.h"

using cs225::HSLAPixel;
using cs225::PNG;

TEST_CASE("Constructs Matrix Correctly", "[pagerank][1]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    int num_v = g->getNumV();
    double **correct_matrix = new double*[num_v];

    correct_matrix[0] = new double[num_v];
    correct_matrix[0][0] = 0;
    correct_matrix[0][1] = 0.5;
    correct_matrix[0][2] = 0; // should be 0
    correct_matrix[0][3] = 0; // should be 0

    correct_matrix[1] = new double[num_v];
    correct_matrix[1][0] = 0.3333333333; // shoudl be 1/3
    correct_matrix[1][1] = 0;
    correct_matrix[1][2] = 0;
    correct_matrix[1][3] = 0;

    correct_matrix[2] = new double[num_v];
    correct_matrix[2][0] = 0.3333333333; // 1/3
    correct_matrix[2][1] = 0;
    correct_matrix[2][2] = 0;
    correct_matrix[2][3] = 0.5;

    correct_matrix[3] = new double[num_v];
    correct_matrix[3][0] = 0.3333333333; //1/3
    correct_matrix[3][1] = 0.5;
    correct_matrix[3][2] = 1;
    correct_matrix[3][3] = 0;

    // run actual pagerank method
    PageRank page_rank(g);
    double** matrix_from_method = page_rank.CreateMatrix();

    std::cout << num_v << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "i: " << i << std::endl;
            std::cout << "j: " << j << std::endl;
            REQUIRE(correct_matrix[i][j] == matrix_from_method[i][j]);
        }
    }
}

TEST_CASE("Constructs Matrix Correctly Part 2", "[pagerank][2]") {
    Graph* g = constructGraph("data/pr_data_v.txt.txt", "data/pr_data_e.txt", 100);
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

TEST_CASE("Test Columns Add to 1", "[pagerank][3]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    int num_v = g->getNumV();

    // run actual pagerank method
    PageRank page_rank(g);
    double** matrix_from_method = page_rank.CreateMatrix();

    double sum_first_column = 0;
    double sum_second_column = 0;
    double sum_third_column = 0;
    double sum_fourth_column = 0;
    for (int i = 0; i < num_v; i++) {
        sum_first_column += matrix_from_method[i][0];
        sum_second_column += matrix_from_method[i][1];
        sum_third_column += matrix_from_method[i][2];
        sum_fourth_column += matrix_from_method[i][3];
    }

    REQUIRE(sum_first_column == 1);
    REQUIRE(sum_second_column == 1);
    REQUIRE(sum_third_column == 1);
    REQUIRE(sum_fourth_column == 1);
}

TEST_CASE("Test Columns Add to 1 Part 2", "[pagerank][4]") {
Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    int num_v = g->getNumV();

    // run actual pagerank method
    PageRank page_rank(g);
    double** matrix_from_method = page_rank.CreateMatrix();

    double sum_first_column = 0;
    double sum_second_column = 0;
    double sum_third_column = 0;
    double sum_fourth_column = 0;
    for (int i = 0; i < num_v; i++) {
        sum_first_column += matrix_from_method[i][0];
        sum_second_column += matrix_from_method[i][1];
        sum_third_column += matrix_from_method[i][2];
        sum_fourth_column += matrix_from_method[i][3];
    }

    REQUIRE(sum_first_column == 1);
    REQUIRE(sum_second_column == 1);
    REQUIRE(sum_third_column == 1);
    REQUIRE(sum_fourth_column == 1);
}

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

TEST_CASE("Test getInboundLinks()", "[pagerank][7]") {
    Graph* g = constructGraph("data/pr_data_v.txt", "data/pr_data_e.txt", 100);
    PageRank page_rank(g);
    map<int, vector<int>> correct_inbound_links;

    for (auto pair : page_rank.GetInboundLinks()) {
        cout << "Vector index: " << pair.first << endl;
        cout << "Inbound links: ";
        for (auto v_index : pair.second) {
            cout << v_index << " ";
        }
        cout << endl;
    }

    REQUIRE(true == false);
}


TEST_CASE("Test getInboundLinks() Part 2", "[pagerank][8]") {
    //Graph* g = constructGraph("data/pr_data_v.txt.txt", "data/pr_data_v.txt.txt");
}

TEST_CASE("Test pagerank on small dataset", "[pagerank][11]") {
    //Graph* g = constructGraph("data/pr_data_v.txt.txt", "data/pr_data_v.txt.txt");
}