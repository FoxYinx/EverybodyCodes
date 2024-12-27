#include <fstream>
#include <iostream>
#include <array>
#include <cstdint>
#include <vector>

#define COLUMNNB 4
#define ROUNDNB 1000

using namespace std;

int year2024_day5_puzzle3() {
    ifstream f("ressources/Year2024/day5/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<vector<int>, COLUMNNB> clappers;
    while (getline(f, s)) {
        for (int i = 0; i < COLUMNNB; i++) {
            try {
                clappers[i].push_back(stoi(s.substr(i * 5, 5)));
            } catch (const invalid_argument& e) {
                cerr << "Invalid argument: " << e.what() << endl;
                return 1;
            } catch (const out_of_range& e) {
                cerr << "Out of range: " << e.what() << endl;
                return 1;
            }
        }
    }

    uint64_t hightestNumber = 0;

    for (int round = 0; round < ROUNDNB; round++) {
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
        if (const uint64_t number = stoull(temp); number > hightestNumber) hightestNumber = number;
    }

    cout << hightestNumber << endl;
    return 0;
}

