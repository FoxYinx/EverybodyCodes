#include <iostream>
#include "utils.h"

char findLetter(const array<array<char, SIZE>, SIZE>& map, const int& y, const int& x) {
    for (int row = 0; row < SIZE; row++) {
        if (map[row][x] == '.' || map[row][x] == '*') continue;
        const char cr = map[row][x];
        for (int column = 0; column < SIZE; column++) {
            if (map[y][column] == '.' || map[y][column] == '*') continue;
            const char cc = map[y][column];
            if (cr == cc) return cc;
        }
    }
    cerr << "Failed to find new letter" << endl;
    return '.';
}
