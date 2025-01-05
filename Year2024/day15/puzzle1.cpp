#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day15_puzzle1() {
    ifstream f("ressources/Year2024/day15/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<vector<char>> map;
    vector<Node> flowers;
    Node start = {};
    int line = 0;
    while (getline(f, s)) {
        vector<char> temp;
        for (int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
            if (s[i] == 'H') flowers.emplace_back(i, line);
            if (s[i] == '.' && line == 0) start = {i, 0};
        }
        map.push_back(temp);
        line++;
    }

    int min = numeric_limits<int>::max();
    for (const Node& end : flowers) {
        int dist = dijkstra(start, end, map) * 2;
        if (dist < min) min = dist;
    }

    cout << min << endl;
    return 0;
}
