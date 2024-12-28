#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int year2024_day9_puzzle1() {
    ifstream f("ressources/Year2024/day9/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int total = 0;
    while (getline(f, s)) {
        int input = stoi(s);
        total += floor(input / 10);
        input %= 10;
        total += floor(input / 5);
        input %= 5;
        total += floor(input / 3);
        input %= 3;
        total += input;
    }

    cout << total << endl;
    return 0;
}