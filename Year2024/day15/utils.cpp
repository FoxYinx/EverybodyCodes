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

vector<vector<Node>> generatePermutations(const map<char, vector<Node>>& flowers) {
    vector<vector<Node>> result;
    vector<Node> current;
    vector<vector<Node>> allNodes;

    // Collect all vectors of Nodes from the map
    for (const auto& pair : flowers | views::values) {
        allNodes.push_back(pair);
    }

    // Helper function to generate permutations
    function<void(int)> permute = [&](const int index) {
        if (index == allNodes.size()) {
            // Generate all possible orders of the current combination
            sort(current.begin(), current.end());
            do {
                result.push_back(current);
            } while (next_permutation(current.begin(), current.end()));
            return;
        }
        for (const Node& node : allNodes[index]) {
            current.push_back(node);
            permute(index + 1);
            current.pop_back();
        }
    };

    permute(0);
    return result;
}