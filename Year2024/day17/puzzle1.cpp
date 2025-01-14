#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#include "DisjointSet.h"

using namespace std;

int distance(const Pos& a, const Pos& b);
int constellationSize(const vector<Edge>& constellation);
vector<Edge> createEdges(const vector<Pos>& G);
vector<Edge> sortEdgesByWeight(const vector<Pos>& G);
vector<Edge> kruskal(const vector<Pos>& G);

int year2024_day17_puzzle1() {
    ifstream f("ressources/Year2024/day17/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<Pos> stars;
    int line = 0;
    while(getline(f, s)) {
        for (int i = 0; i < s.size(); i++) if (s[i] == '*') stars.emplace_back(i, line);
        line++;
    }

    vector<Edge> constellation = kruskal(stars);

    cout << constellationSize(constellation) << endl;
    return 0;
}

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

