#include <fstream>
#include <iostream>
#include <array>
#include <vector>

#define COLUMNNB 4
#define ROUNDNB 10

using namespace std;

int year2024_day5_puzzle1() {
    ifstream f("ressources/Year2024/day5/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<vector<int>, COLUMNNB> clappers;
    while (getline(f, s)) {
        for (int i = 0; i < COLUMNNB; i++) clappers[i].push_back(stoi(&s[i * 2]));
    }

    cout << "Round  Number" << endl;
    for (int round = 0; round < ROUNDNB; round++) {
        int clapper = clappers[round % COLUMNNB].front();
        clappers[round % COLUMNNB].erase(clappers[round % COLUMNNB].begin());
        if (clapper > clappers[(round + 1) % COLUMNNB].size()) {
            clappers[(round + 1) % COLUMNNB].insert(clappers[(round + 1) % COLUMNNB].end() - (clapper - 1 - clappers[(round + 1) % COLUMNNB].size()), clapper);
        } else {
            clappers[(round + 1) % COLUMNNB].insert(clappers[(round + 1) % COLUMNNB].begin() + clapper - 1, clapper);
        }

        cout << round + 1 << ":     ";
        for (const auto& c : clappers) {
            cout << c[0] << " ";
        }
        cout << endl;
    }

    return 0;
}

