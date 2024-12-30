#include <iostream>
#include "utils.h"

char findLetter(const array<array<char, SIZE>, SIZE>& map, const int& y, const int& x) {
    for (int row = 0; row < SIZE; row++) {
        if (map[row][x] == '.' || map[row][x] == '*') continue;
        const char cr = map[row][x];
        for (int column = 0; column < SIZE; column++) {
            if (map[y][column] == '.' || map[y][column] == '*') continue;
            if (const char cc = map[y][column]; cr == cc) return cc;
        }
    }
    return '.';
}

char findLetterVector(const vector<vector<char>>& map, const int& y, const int& x, const int& cornerY, const int& cornerX) {
    for (int row = 0; row < SIZE; row++) {
        if (map[cornerY + row][x] == '.' || map[cornerY + row][x] == '*') continue;
        const char cr = map[cornerY + row][x];
        for (int column = 0; column < SIZE; column++) {
            if (map[y][cornerX + column] == '.' || map[y][cornerX + column] == '*') continue;
            if (const char cc = map[y][cornerX + column]; cr == cc) return cc;
        }
    }
    return '.';
}

bool trytoSolve(vector<vector<char>>& map, const int&y, const int& x) {
    bool flag = true;
    for (int row = 2; row < SIZE - 2; row++) {
        for (int column = 2; column < SIZE - 2; column++) {
            const char newLetter = findLetterVector(map, row + y, column + x, y, x);
            if (newLetter == '.') flag = false;
            map[row + y][column + x] = newLetter;
        }
    }
    return flag;
}
