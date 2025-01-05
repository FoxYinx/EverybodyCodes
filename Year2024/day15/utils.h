#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>

using namespace std;

struct Node {
    int x;
    int y;
    int dist;

    bool operator>(const Node& other) const;
    bool operator<(const Node& other) const;
};

int dijkstra(const Node& start, const Node& end, const vector<vector<char>>& map);
vector<vector<Node>> generatePermutations(const map<char, vector<Node>>& flowers);

#endif //UTILS_H
