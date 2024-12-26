#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

int year2024_day1_puzzle1() {
    ifstream f("ressources/Year2024/day1/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int potions = 0;
    getline(f, s);
    for (const char& c : s) {
        potions += processChar(c);
    }

    cout << potions << endl;
    return 0;
}
