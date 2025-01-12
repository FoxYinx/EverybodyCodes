#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include "utils.h"

using namespace std;

int year2024_day15_puzzle3() {
    ifstream f("ressources/Year2024/day15/part3.txt");

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

    int minMiddle = numeric_limits<int>::max();
    map<pair<Node, Node>, int> memo = {};

    auto processPermutation = [&](const vector<Node>& combi) {
        int dist = 0;
        vector<Node> tempCombi = combi;
        tempCombi.insert(tempCombi.begin(), start);
        tempCombi.insert(tempCombi.end(), start);

        bool toContinue = true;
        if (carte[tempCombi[1].y][tempCombi[1].x] != 'G') {
            toContinue = false;
        }
        if (toContinue) {
            for (int i = 0; i < tempCombi.size() - 1; i++) {
                dist += dijkstra(tempCombi[i], tempCombi[i + 1], carte, memo);
            }
            if (dist < minMiddle) {
                minMiddle = dist;
            }
        }
    };

    map<char, vector<Node>> middle = {};
    for (auto &[key, value] : flowers) {
        if (carte[value[0].y][value[0].x] == 'G' || carte[value[0].y][value[0].x] == 'H' || carte[value[0].y][value[0].x] == 'I' || carte[value[0].y][value[0].x] == 'J' || carte[value[0].y][value[0].x] == 'K') {
            middle[key] = value;
        }
    }
    middle['E'] = vector(1, flowers['E'][1]);
    middle['R'] = vector(1, flowers['R'][0]);

    generatePermutations(middle, processPermutation);

    int minLeft = numeric_limits<int>::max();
    auto processPermutationLeft = [&](const vector<Node>& combi) {
        int dist = 0;
        vector<Node> tempCombi = combi;
        tempCombi.insert(tempCombi.begin(), flowers['E'][1]);
        tempCombi.insert(tempCombi.end(), flowers['E'][1]);
        for (int i = 0; i < tempCombi.size() - 1; i++) {
            dist += dijkstra(tempCombi[i], tempCombi[i + 1], carte, memo);
        }
        if (dist < minLeft) {
            minLeft = dist;
        }
    };

    map<char, vector<Node>> left = {};
    for (auto &[key, value] : flowers) {
        if (carte[value[0].y][value[0].x] == 'A' || carte[value[0].y][value[0].x] == 'B' || carte[value[0].y][value[0].x] == 'C' || carte[value[0].y][value[0].x] == 'D') {
            left[key] = value;
        }
    }
    generatePermutations(left, processPermutationLeft);

    int minRight = numeric_limits<int>::max();
    auto processPermutationRight = [&](const vector<Node>& combi) {
        int dist = 0;
        vector<Node> tempCombi = combi;
        tempCombi.insert(tempCombi.begin(), flowers['R'][0]);
        tempCombi.insert(tempCombi.end(), flowers['R'][0]);
        for (int i = 0; i < tempCombi.size() - 1; i++) {
            dist += dijkstra(tempCombi[i], tempCombi[i + 1], carte, memo);
        }
        if (dist < minRight) {
            minRight = dist;
        }
    };

    map<char, vector<Node>> right = {};
    for (auto &[key, value] : flowers) {
        if (carte[value[0].y][value[0].x] == 'N' || carte[value[0].y][value[0].x] == 'O' || carte[value[0].y][value[0].x] == 'P' || carte[value[0].y][value[0].x] == 'Q') {
            right[key] = value;
        }
    }
    generatePermutations(right, processPermutationRight);

    cout << "Middle part takes : " << minMiddle << endl;
    cout << "Left part takes : " << minLeft << endl;
    cout << "Right part takes : " << minRight << endl;
    cout << "Total is " << minMiddle + minLeft + minRight << endl;

    return 0;
}
