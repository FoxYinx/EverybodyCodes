#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

int year2024_day1_puzzle2() {
    ifstream f("ressources/Year2024/day1/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int potions = 0;
    getline(f, s);
    for (int i = 0; i < s.size(); i += 2) {
        const char c1 = s.at(i);
        const char c2 = s.at(i + 1);
        if (c1 == 'x') potions += processChar(c2);
        else if (c2 == 'x') potions += processChar(c1);
        else potions += processChar(c1) + processChar(c2) + 2;
    }

    cout << potions << endl;
    return 0;
}
