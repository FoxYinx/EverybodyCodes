#include <fstream>
#include <iostream>
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

    vector map(BIGSIZE, vector(BIGSIZE, ' '));

    string s;
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < BIGSIZE; i++) {
            map[line][i] = s[i];
        }
        line++;
    }

    for (int i = 0; i < BIGSIZE - 2; i += 6) {
        for (int j = 0; j < BIGSIZE - 2; j += 6) {
            cout << trytoSolve(map, i, j) << endl;
        }
    }

    return 0;
}
