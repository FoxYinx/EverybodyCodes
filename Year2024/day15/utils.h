#ifndef UTILS_H
#define UTILS_H

#include <vector>

using namespace std;

struct Node {
    int x;
    int y;
    int dist;

    bool operator>(const Node& other) const;
};

int dijkstra(const Node& start, const Node& end, const vector<vector<char>>& map);

#endif //UTILS_H
