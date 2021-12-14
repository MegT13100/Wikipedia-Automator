#include "PageRank.h"

PageRank::PageRank(Graph* g) : graph_(g) { }

/*
    Creates a matrix representation of the probabilities
*/
double** PageRank::CreateMatrix() {
    int num_v = graph_->getNumV();
    double** matrix = new double*[num_v];
    for (int i = 0; i < num_v; ++i) { // row
        matrix[i] = new double[num_v];
        for (int j = 0; j < num_v; ++j) { // col
            if (i != j && graph_->adjMatrix[i][j]) {
                matrix[i][j] = 1 / (double)(graph_->getVertices()[j]->degree_);
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

/*
    Returns the PageRanks of the vertices as a list (in order of the vertex indices)

    PR(A) = (1-d) + d(PR(T_i)/C(T_i) + ... + PR(T_n)/C(T_n))
    - PR(A) is the PageRank of page A
    - PR(T_i) is the PageRank pages T_i which link to page A
    - C(T_i) is the number of outbound links on page T_i
    - d is a damping factor which can be set between 0 and 1 (usually 0.85)
*/
vector<double> PageRank::FindPageRanks(double d, size_t num_iterations) {
    int num_v = graph_->getNumV();

    // Initial page rank assigned to every page
    // 1/n for every vector, where n is the number of vectors
    vector<double> curr(num_v, 0);
    vector<double> prev(num_v, 1 / num_v);
    map<int, vector<int>> inbound_links = getInboundLinks();

    for (size_t itr = 0; itr < num_iterations; ++itr) {
        for (int i = 0; i < num_v; ++i) {
            int sum = 1 - d;
            for (int vertex_index : inbound_links[i]) {
                int num_outgoing_links = graph_->getVertices()[vertex_index]->degree_;
                if (num_outgoing_links > 0) {
                    sum += prev[vertex_index] / num_outgoing_links;
                }
            }
            curr[i] = d * sum;
        }
        prev = curr;
    }

    return curr;
}

/*
    Maps a vertex A's index to a list of vertices (their indices) that link to A
*/
map<int, vector<int>> PageRank::getInboundLinks() {
    map<int, vector<int>> inbound_links;
    
    // initialize the map
    for (int i = 0; i < graph_->getNumV(); ++i) {
        inbound_links[i] = vector<int>();
    }

    // v is the destination vertex of an edge and u is the source vertex of an edge
    for (Edge* edge : graph_->getEdgeList()) {
        inbound_links[edge->v.index_].push_back(edge->u.index_);
    }

    return inbound_links;
}

// ADD SMALL VISUALIZATION OR THING
// method that takes in a weblink and returns the relative importance of it 
// so takes in an edge and returns its pagerank 


/*
    NOTE: Not using currently

    PR_{t+1} = H PR_t
*/
void PageRank::PowerMethod(double** matrix) {
    // Initial page rank assigned to every page
    // 1/n for every vector, where n is the number of vectors
    vector<double> vector(graph_->getNumV(), 1 / graph_->getNumV());
}