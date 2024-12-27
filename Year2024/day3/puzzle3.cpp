#include <fstream>
#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day3_puzzle3() {
    ifstream f("ressources/Year2024/day3/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<vector<int>> map;
    while (getline(f, s)) {
        vector<int> temp = {};
        for (const char& i : s) temp.emplace_back(i == '#' ? 1 : 0);
        map.push_back(temp);
    }

    digDiag(map, 2);

    int removableBlocks = 0;
    for (const auto& row : map) for (const int& i : row) removableBlocks += i;
    cout << removableBlocks << endl;
    return 0;
}
