#include "DisjointSet.h"

#include <tuple>

bool Pos::operator<(const Pos &other) const{
        return tie(x, y) < tie(other.x, other.y);
}

bool Edge::operator<(const Edge &other) const {
        return weight < other.weight;
}


DisjointSet::DisjointSet(const vector<Pos> &positions) {
        const int n = positions.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
                parent[i] = i;
                posToIndex[positions[i]] = i;
        }
}

int DisjointSet::find(const int &u) {
        if (parent[u] != u) {
                parent[u] = find(parent[u]);
        }
        return parent[u];
}


int DisjointSet::find(const Pos &p) {
        return find(posToIndex[p]);
}

void DisjointSet::unite(const Pos &p1, const Pos &p2) {
        const int rootU = find(p1);
        const int rootV = find(p2);
        if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                        parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                        parent[rootU] = rootV;
                } else {
                        parent[rootV] = rootU;
                        rank[rootU]++;
                }
        }
}
