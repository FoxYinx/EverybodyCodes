#include <queue>
#include <array>
#include <vector>
#include <iostream>
#include <limits>
#include "utils.h"

uint64_t dijkstra(const vector<vector<Node>>& map, const Node& start) {
    constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    vector dist(map.size(), vector(map[0].size(), numeric_limits<uint64_t>::max()));
    dist[start.y][start.x] = 0;
    priority_queue<Node, vector<Node>, greater<>> pile;
    pile.push(start);

    while (!pile.empty()) {
        const Node node = pile.top();
        pile.pop();

        if (node.value == 'E') return node.dist;

        for (const auto &[dx, dy]: directions) {
            const int nx = node.x + dx;
            const int ny = node.y + dy;
            if (nx >= 0 && nx < map[0].size() && ny >= 0 && ny < map.size() && map[ny][nx].value != '#') {
                uint64_t diff = map[ny][nx].dist > map[node.y][node.x].dist ? map[ny][nx].dist - map[node.y][node.x].dist : map[node.y][node.x].dist - map[ny][nx].dist;
                uint64_t diff2 = map[ny][nx].dist > map[node.y][node.x].dist ? 10 + map[node.y][node.x].dist - map[ny][nx].dist : 10 + map[ny][nx].dist - map[node.y][node.x].dist;
                uint64_t minimum = min(diff, diff2);

                if (node.dist + minimum + 1 < dist[ny][nx]) {
                    dist[ny][nx] = node.dist + minimum + 1;
                    pile.push({nx, ny, map[ny][nx].value, dist[ny][nx]});
                }
            }
        }
    }

    cerr << "Dijkstra failed!" << endl;
    return -1;
}
