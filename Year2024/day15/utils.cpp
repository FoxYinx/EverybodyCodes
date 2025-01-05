#include <array>
#include "utils.h"

#include <limits>
#include <queue>

bool Node::operator>(const Node& other) const {
    return dist > other.dist;
}


int dijkstra(const Node& start, const Node& end, const vector<vector<char>>& map) {
    constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    vector dist(map.size(), vector(map[0].size(), numeric_limits<int>::max()));

    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push(start);
    dist[start.y][start.x] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (node.x == end.x && node.y == end.y) return node.dist;

        for (const auto &[dx, dy] : directions) {
            const int nx = node.x + dx;
            const int ny = node.y + dy;
            if (nx >= 0 && nx < map[0].size() && ny >= 0 && ny < map.size() && map[ny][nx] != '#' && node.dist + 1 < dist[ny][nx]) {
                dist[ny][nx] = node.dist + 1;
                pq.emplace(nx, ny, dist[ny][nx]);
            }
        }
    }

    return -1;
}
