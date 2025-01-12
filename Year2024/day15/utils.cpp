#include <array>
#include <limits>
#include <queue>
#include <algorithm>
#include <ranges>
#include <functional>
#include "utils.h"


bool Node::operator>(const Node& other) const {
    return dist > other.dist;
}

bool Node::operator<(const Node& other) const {
    if (x != other.x) {
        return x < other.x;
    }
    return y < other.y;
}

bool Node::operator==(const Node& other) const {
    return x == other.x && y == other.y;
}


int dijkstra(const Node& start, const Node& end, const vector<vector<char>>& carte, map<pair<Node, Node>, int>& memo) {
    if (memo.contains({start, end})) return memo[{start, end}];
    if (memo.contains({end, start})) return memo[{end, start}];
    constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    vector dist(carte.size(), vector(carte[0].size(), numeric_limits<int>::max()));

    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push(start);
    dist[start.y][start.x] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (node.x == end.x && node.y == end.y) {
            memo[{start, end}] = node.dist;
            return node.dist;
        }

        for (const auto &[dx, dy] : directions) {
            const int nx = node.x + dx;
            const int ny = node.y + dy;
            if (nx >= 0 && nx < carte[0].size() && ny >= 0 && ny < carte.size() && carte[ny][nx] != '#' && carte[ny][nx] != '~' && node.dist + 1 < dist[ny][nx]) {
                dist[ny][nx] = node.dist + 1;
                pq.emplace(nx, ny, dist[ny][nx]);
            }
        }
    }

    return -1;
}

void generatePermutations(const map<char, vector<Node>>& flowers, function<void(const vector<Node>&)> callback) {
    vector<Node> current;
    vector<vector<Node>> allNodes;
    vector<char> keys;

    // Collect all vectors of Nodes from the map and store the keys
    for (const auto& pair : flowers) {
        allNodes.push_back(pair.second);
        keys.push_back(pair.first);
    }

    // Helper function to generate combinations
    function<void(int)> combine = [&](int index) {
        if (index == allNodes.size()) {
            callback(current);
            return;
        }
        for (const Node& node : allNodes[index]) {
            current.push_back(node);
            combine(index + 1);
            current.pop_back();
        }
    };

    // Generate all permutations of keys
    do {
        // Reorder allNodes according to the current permutation of keys
        vector<vector<Node>> permutedNodes;
        for (char key : keys) {
            permutedNodes.push_back(flowers.at(key));
        }
        allNodes = permutedNodes;
        combine(0);
    } while (next_permutation(keys.begin(), keys.end()));
}