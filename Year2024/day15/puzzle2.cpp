#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include "utils.h"

using namespace std;

int year2024_day15_puzzle2() {
    ifstream f("ressources/Year2024/day15/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<vector<char>> carte;
    map<char, vector<Node>> flowers;
    Node start = {};
    int line = 0;
    while (getline(f, s)) {
        vector<char> temp;
        for (int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
            if (isalpha(s[i])) flowers[s[i]].emplace_back(i, line);
            if (s[i] == '.' && line == 0) start = {i, 0};
        }
        carte.push_back(temp);
        line++;
    }

    vector combinaisons = generatePermutations(flowers);

    int min = numeric_limits<int>::max();
    for (vector<Node>& combi : combinaisons) {
        int dist = 0;
        combi.insert(combi.begin(), start);
        combi.insert(combi.end(), start);
        for (int i = 0; i < combi.size() - 1; i++) {
            dist += dijkstra(combi[i], combi[i + 1], carte);
        }
        if (dist < min) min = dist;
    }

    cout << min << endl;
    return 0;
}
