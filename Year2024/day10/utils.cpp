#include <iostream>
#include <map>
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

bool trytoSolve(vector<vector<char>>& map, const int& y, const int& x) {
    bool flag = true;
    for (int row = 2; row < SIZE - 2; row++) {
        for (int column = 2; column < SIZE - 2; column++) {
            const char newLetter = findLetterVector(map, row + y, column + x, y, x);
            if (newLetter == '.') flag = false;
            map[row + y][column + x] = newLetter;
        }
    }
    if (!flag) {
        return tryToComplete(map, y, x);
    }
    return true;
}

bool tryToComplete(vector<vector<char>>& wall, const int& y, const int& x) {
    bool flag = true;
    for (int column = 2; column < SIZE - 2; column++) {
        int nullx, nully;
        for (int row = 0; row < SIZE; row++) {
            const char letter = wall[y + row][x + column];
            if (letter == '.') continue;
            bool hasDouble = false;
            for (int rowPointer = 0; rowPointer < SIZE; rowPointer++) {
                if (rowPointer == row) continue;
                if (wall[y + rowPointer][x + column] == '.') {
                    nullx = x + column;
                    nully = y + rowPointer;
                } else if (wall[y + rowPointer][x + column] == letter) hasDouble = true;
            }
            if (!hasDouble) {
                wall[nully][nullx] = letter;
                break;
            }
        }
    }
    for (int row = 2; row < SIZE - 2; row++) {
        int nullx, nully;
        for (int column = 0; column < SIZE; column++) {
            const char letter = wall[y + row][x + column];
            if (letter == '?') break;
            if (letter == '.') continue;
            bool hasDouble = false;
            bool isNotQuestionMark = true;
            for (int columnPointer = 0; columnPointer < SIZE; columnPointer++) {
                if (columnPointer == column) continue;
                if (wall[y + row][x + columnPointer] == '?') {
                    isNotQuestionMark = false;
                    break;
                }
                if (wall[y + row][x + columnPointer] == '.') {
                    nullx = x + columnPointer;
                    nully = y + row;
                } else if (wall[y + row][x + columnPointer] == letter) hasDouble = true;
            }
            if (!hasDouble && isNotQuestionMark) {
                wall[nully][nullx] = letter;
                break;
            }
        }
    }
    return flag;
}
