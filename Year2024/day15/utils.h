#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>
#include <functional>

using namespace std;

struct Node {
    int x;
    int y;
    int dist;

    bool operator>(const Node& other) const;
    bool operator<(const Node& other) const;
    bool operator==(const Node& other) const;
};

int dijkstra(const Node& start, const Node& end, const vector<vector<char>>& carte, map<pair<Node, Node>, int>& memo);
void generatePermutations(const map<char, vector<Node>>& flowers, function<void(const vector<Node>&)> callback);

#endif //UTILS_H
