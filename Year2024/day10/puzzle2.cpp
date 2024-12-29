#include <fstream>
#include <iostream>
#include <array>
#include "utils.h"

using namespace std;

int year2024_day10_puzzle2() {
    ifstream f("ressources/Year2024/day10/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    array<array<char, SIZE>, SIZE> map = {};

    string s;
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            map[line][i] = s[i];
        }
        line++;
    }

    int power = 0;
    int pos = 1;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (map[y][x] == '.') {
                const char newLetter = findLetter(map, y, x);
                power += (newLetter - '@') * pos;
                map[y][x] = newLetter;
                pos++;
            }
        }
    }

    cout << power << endl;
    return 0;
}
