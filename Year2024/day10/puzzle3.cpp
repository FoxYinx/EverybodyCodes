#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day10_puzzle3() {
    ifstream f("ressources/Year2024/day10/part3.txt");

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
                            power += (newLetter - '@') * pos;
                            m[y][x] = newLetter;
                            pos++;
                        }
                    }
                }
            }
            map.clear();
            map.emplace_back();
            line++;
            continue;
        }

        int whichmap = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (line % (SIZE + 1) == 0) {
                    map.emplace_back();
                }
                whichmap++;
            }
            map[whichmap][line % (SIZE + 1)][i % (SIZE + 1)] = s[i];
        }
        line++;
    }

    cout << power << endl;
    return 0;
}
