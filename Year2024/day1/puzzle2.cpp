#include <fstream>
#include <iostream>

using namespace std;

int processChar(const char& c);

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

int processChar(const char& c) {
    if (c == 'B') return 1;
    if (c == 'C') return 3;
    if (c == 'D') return 5;
    return 0;
}