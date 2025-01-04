#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day13_puzzle2() {
    ifstream f("ressources/Year2024/day13/part2.txt");

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