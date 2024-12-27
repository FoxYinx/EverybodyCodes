#include <fstream>
#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day4_puzzle1() {
    ifstream f("ressources/Year2024/day4/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<int> nails;
    while (getline(f, s)) {
        nails.push_back(stoi(s));
    }

    cout << flattenNails(nails);
    return 0;
}
