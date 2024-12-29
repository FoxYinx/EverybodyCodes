#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day9_puzzle2() {
    ifstream f("ressources/Year2024/day9/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int total = 0;
    const vector stamps = {30, 25, 24, 20, 16, 15, 10, 5, 3, 1};
    while (getline(f, s)) {
        const int input = stoi(s);
        map<int, int> memory;
        total += findMin(input, stamps, memory);
    }

    cout << total << endl;
    return 0;
}
