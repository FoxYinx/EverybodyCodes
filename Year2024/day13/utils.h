#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <vector>

using namespace std;

struct Node {
    int x;
    int y;
    char value;
    uint64_t dist;

    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

uint64_t dijkstra(const vector<vector<Node>>& map, const Node& start);

#endif //UTILS_H
