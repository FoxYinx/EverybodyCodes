#include <fstream>
#include <iostream>
#include <array>
#include <cstdint>
#include <vector>
#include <map>

#define COLUMNNB 4
#define ROUNDNB 10

using namespace std;

int year2024_day5_puzzle2() {
    ifstream f("ressources/Year2024/day5/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<vector<int>, COLUMNNB> clappers;
    while (getline(f, s)) {
        for (int i = 0; i < COLUMNNB; i++) clappers[i].push_back(stoi(&s[i * 3]));
    }

    map<uint64_t, int> repetitions;

    for (int round = 0;; round++) {
        int clapperValue = clappers[round % COLUMNNB].front();
        int clapper = clappers[round % COLUMNNB].front() % (clappers[(round + 1) % COLUMNNB].size() * 2);
        if (clapper == 0) clapper = clappers[(round + 1) % COLUMNNB].size() * 2;
        clappers[round % COLUMNNB].erase(clappers[round % COLUMNNB].begin());
        if (clapper > clappers[(round + 1) % COLUMNNB].size()) {
            clappers[(round + 1) % COLUMNNB].insert(clappers[(round + 1) % COLUMNNB].end() - (clapper - 1 - clappers[(round + 1) % COLUMNNB].size()), clapperValue);
        } else {
            clappers[(round + 1) % COLUMNNB].insert(clappers[(round + 1) % COLUMNNB].begin() + clapper - 1, clapperValue);
        }

        string temp;
        for (const auto& c : clappers) {
            temp += to_string(c[0]);
        }
        if (uint64_t shout = stoull(temp); repetitions.contains(shout)) {
            repetitions[shout]++;
            if (repetitions[shout] == 2024) {
                cout << (round + 1) * shout;
                break;
            }
        }
        else repetitions[shout] = 1;
    }

    return 0;
}

