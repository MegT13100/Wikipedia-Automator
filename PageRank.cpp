#include "PageRank.h"

/*
    Creates a matrix representation of the probabilities
*/
double** PageRank::createMatrix(Graph* g) {
    int num_v = g->getNumV();
    double** matrix = new double*[num_v];
    for (int i = 0; i < num_v; ++i) { // row
        matrix[i] = new double[num_v];
        for (int j = 0; j < num_v; ++j) { // col
            if (i != j && g->adjMatrix[i][j]) {
                matrix[i][j] = 1 / (double)(g->getVertices()[j]->degree_);
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}