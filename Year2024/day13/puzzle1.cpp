#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <queue>

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

int year2024_day13_puzzle1() {
    ifstream f("ressources/Year2024/day13/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<vector<Node>> map;
    int line = 0;
    Node start = {};
    while(getline(f, s)) {
        vector<Node> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'S') {
                start = {i, line, s[i], 0};
                temp.push_back({i, line, s[i], 0});
            } else if (s[i] == 'E') {
                temp.push_back({i, line, s[i], 0});
            } else {
                temp.push_back({i, line, s[i], static_cast<uint64_t>(s[i] - '0')});
            }
        }
        map.push_back(temp);
        line++;
    }

    uint64_t fastest = dijkstra(map, start);
    cout << fastest << endl;
    return 0;
}

uint64_t dijkstra(const vector<vector<Node>>& map, const Node& start) {
    constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
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
                uint64_t diff2 =
                pile.push({nx, ny, map[ny][nx].value, node.dist + diff + 1});
            }
        }
    }

    cerr << "Dijkstra failed!" << endl;
    return -1;
}