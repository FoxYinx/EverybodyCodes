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

    int min = numeric_limits<int>::max();
    vector<Node> answer = {};
    map<pair<Node, Node>, int> memo = {};


    auto processPermutation = [&](const vector<Node>& combi) {
        int dist = 0;
        vector<Node> tempCombi = combi;
        tempCombi.insert(tempCombi.begin(), start);
        tempCombi.insert(tempCombi.end(), start);

        bool toContinue = false;
        for (int i = 0; i < tempCombi.size() - 1; i++) {
            if (tempCombi[i] == tempCombi[i + 1]) {
                toContinue = true;
                break;
            }
        }
        if (!toContinue) {
            for (int i = 0; i < tempCombi.size() - 1; i++) {
                dist += dijkstra(tempCombi[i], tempCombi[i + 1], carte, memo);
            }
            if (dist < min) {
                min = dist;
                answer = tempCombi;
            }
        }
    };

    generatePermutations(flowers, processPermutation);

    cout << "Min = " << min << endl;
    for (const Node& node : answer) {
        cout << "(y = " << node.y << ", x = " << node.x << "): " << carte[node.y][node.x] << endl;
    }
    cout << "------------------" << endl;

    return 0;
}
