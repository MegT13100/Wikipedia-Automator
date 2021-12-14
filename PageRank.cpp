#include "PageRank.h"

#include <algorithm>
#include <math.h>

PageRank::PageRank(Graph* g) : graph_(g) { }

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
    vector<double> prev(num_v, 1.0 / (double)num_v);
    map<int, vector<int>> inbound_links = GetInboundLinks();

    for (size_t itr = 0; itr < num_iterations; ++itr) {
        for (int i = 0; i < num_v; ++i) {
            double sum = 0;
            for (int vertex_index : inbound_links[i]) {
                double num_outgoing_links = double(graph_->vertices[vertex_index]->degree_);
                if (num_outgoing_links > 0) {
                    sum += prev[vertex_index] / num_outgoing_links;
                }
            }
            curr[i] = ((1 - d) / (double)num_v) + (d * sum);
        }
        prev = curr;
    }

    return curr;
}

/*
    Maps a vertex A's index to a list of vertices (their indices) that link to A
*/
map<int, vector<int>> PageRank::GetInboundLinks() {
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

// Comparison function for PrintPageRanks sorting
bool cmp(pair<string, double>& a, pair<string, double>& b) {
    return a.second > b.second;
}

void PageRank::PrintPageRanks(vector<double> page_ranks) {
    map<string, double> map = MapPageRanks(page_ranks);

    vector<pair<string, double>> ranking;

    for (auto& pair : map) {
        ranking.push_back(pair);
    }

    sort(ranking.begin(), ranking.end(), cmp);

    cout << "PageRanks (highest to lowest)" << endl;
    int rank = 1;
    for (auto& pair : ranking) {
        cout << rank << ". " << pair.first << " " << pair.second << endl;
        rank++;
    }
}

map<string, double> PageRank::MapPageRanks(vector<double> page_ranks) {
    map<string, double> map;

    for (size_t i = 0; i < page_ranks.size(); ++i) {
        map[graph_->vertices[i]->name_] = page_ranks[i];
    }

    return map;
}