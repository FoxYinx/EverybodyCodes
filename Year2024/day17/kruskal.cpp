#include <algorithm>
#include <numeric>
#include "kruskal.h"

int distance(const Pos& a, const Pos& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int constellationSize(const vector<Edge>& constellation) {
    return accumulate(constellation.begin(), constellation.end(), 1, [](const int& acc, const Edge& edge) {
        return acc + edge.weight + 1;
    });
}

vector<Edge> createEdges(const vector<Pos>& G) {
    vector<Edge> edges;
    for (size_t i = 0; i < G.size(); ++i) {
        for (size_t j = i + 1; j < G.size(); ++j) {
            edges.push_back({G[i], G[j], distance(G[i], G[j])});
        }
    }
    return edges;
}

vector<Edge> sortEdgesByWeight(const vector<Pos>& G) {
    vector<Edge> edges = createEdges(G);
    sort(edges.begin(), edges.end());
    return edges;
}

vector<Edge> kruskal(const vector<Pos>& G) {
    vector<Edge> A;

    DisjointSet disjoint_set(G);
    vector<Edge> edges = sortEdgesByWeight(G);
    for (const Edge& edge : edges) {
        if (disjoint_set.find(edge.u) != disjoint_set.find(edge.v)) {
            A.push_back(edge);
            disjoint_set.unite(edge.u, edge.v);
        }
    }

    return A;
}


