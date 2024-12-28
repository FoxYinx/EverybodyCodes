#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int year2024_day8_puzzle1() {
    ifstream f("ressources/Year2024/day8/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    getline(f, s);
    const int input = stoi(s);
    cout << fixed << setprecision(0) << (pow(ceil(sqrt(input)), 2) - input) * (floor(sqrt(input)) * 2 + 1) << endl;
    return 0;
}