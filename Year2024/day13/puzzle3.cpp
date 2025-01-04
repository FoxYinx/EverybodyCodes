#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day13_puzzle3() {
    ifstream f("ressources/Year2024/day13/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<vector<Node>> map;
    int line = 0;
    while(getline(f, s)) {
        vector<Node> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'S' || s[i] == 'E') {
                temp.push_back({i, line, s[i], 0});
            } else {
                temp.push_back({i, line, s[i], static_cast<uint64_t>(s[i] - '0')});
            }
        }
        map.push_back(temp);
        line++;
    }

    uint64_t fastest = numeric_limits<uint64_t>::max();
    for (int i = 1; i < map.size() - 1; i++) {

        uint64_t temp = dijkstra(map, map[0][i]);
        if (temp < fastest) {
            fastest = temp;
        }
        temp = dijkstra(map, map[static_cast<int>(map.size()) - 1][i]);
        if (temp < fastest) {
            fastest = temp;
        }
        temp = dijkstra(map, map[i][0]);
        if (temp < fastest) {
            fastest = temp;
        }
        temp = dijkstra(map, map[i][static_cast<int>(map[0].size()) - 1]);
        if (temp < fastest) {
            fastest = temp;
        }
    }

    cout << fastest << endl;
    return 0;
}