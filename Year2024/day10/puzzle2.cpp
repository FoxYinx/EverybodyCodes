#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day10_puzzle2() {
    ifstream f("ressources/Year2024/day10/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    vector<array<array<char, SIZE>, SIZE>> map = {};
    map.emplace_back();

    string s;
    int line = 0;
    int power = 0;
    while (getline(f, s)) {
        if (s.empty()) {
            for (auto& m : map) {
                int pos = 1;
                for (int y = 0; y < SIZE; y++) {
                    for (int x = 0; x < SIZE; x++) {
                        if (m[y][x] == '.') {
                            const char newLetter = findLetter(m, y, x);
                            cout << newLetter;
                            power += (newLetter - '@') * pos;
                            m[y][x] = newLetter;
                            pos++;
                        }
                    }
                }
                cout << endl;
            }
            map.clear();
            map.emplace_back();
            line++;
            continue;
        }

        for (int i = 0; i < SIZE; i++) {
            if (s[i] == ' ') {
                map.resize(map.size() + 1);
                continue;
            }
            map[map.size() - 1][line % (SIZE + 1)][i % (SIZE + 1)] = s[i];
        }
        line++;
    }

    cout << power << endl;
    return 0;
}
