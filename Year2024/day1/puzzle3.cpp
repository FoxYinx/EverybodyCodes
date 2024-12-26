#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

int year2024_day1_puzzle3() {
    ifstream f("ressources/Year2024/day1/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int potions = 0;
    getline(f, s);
    for (int i = 0; i < s.size(); i += 3) {
        const char c1 = s.at(i);
        const char c2 = s.at(i + 1);
        const char c3 = s.at(i + 2);
        potions += processChar(c1) + processChar(c2) + processChar(c3);

        int nbX = 0;
        if (c1 == 'x') nbX++;
        if (c2 == 'x') nbX++;
        if (c3 == 'x') nbX++;
        if (nbX == 1) potions += 2;
        else if (nbX == 0) potions += 6;
    }

    cout << potions << endl;
    return 0;
}
