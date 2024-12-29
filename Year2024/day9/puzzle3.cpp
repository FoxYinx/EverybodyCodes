#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

#include "utils.h"

using namespace std;

int year2024_day9_puzzle3() {
    ifstream f("ressources/Year2024/day9/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int total = 0;
    const vector stamps = {101, 100, 75, 74, 50, 49, 38, 37, 30, 25, 24, 20, 16, 15, 10, 5, 3, 1};
    map<int, int> memory;
    while (getline(f, s)) {
        const int input = stoi(s);
        vector<int> values;
        for (int i = ceil(static_cast<double>(input) / 2) - 50; i <= floor(static_cast<double>(input) / 2) + 50; i++) {
            values.push_back(findMin(i, stamps, memory));
        }
        int sub = numeric_limits<int>::max();
        for (int i = 0; i < values.size() / 2 + 1; i++) {
            sub = min(sub, values[i] + values[values.size() - i - 1]);
        }

        total += sub;
    }

    cout << total << endl;
    return 0;
}
