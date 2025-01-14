#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>
#include <map>

using namespace std;

struct Pos {
    int x;
    int y;

    bool operator<(const Pos& other) const;
};

struct Edge {
    Pos u;
    Pos v;
    int weight;

    bool operator<(const Edge& other) const;
};

class DisjointSet {
vector<int> parent;
vector<int> rank;
map<Pos, int> posToIndex;

public:
    DisjointSet(const vector<Pos>& positions);
    int find(const Pos& p);
    int find(const int& u);
    void unite(const Pos& p1, const Pos& p2);
};

#endif
