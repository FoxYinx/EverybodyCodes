#include <fstream>
#include <iostream>
#include <array>
#include "utils.h"

using namespace std;

int year2024_day10_puzzle1() {
    ifstream f("ressources/Year2024/day10/part1.txt");

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

    string rune;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (map[y][x] == '.') {
                const char newLetter = findLetter(map, y, x);
                rune += newLetter;
                map[y][x] = newLetter;
            }
        }
    }

    cout << rune << endl;
    return 0;
}
