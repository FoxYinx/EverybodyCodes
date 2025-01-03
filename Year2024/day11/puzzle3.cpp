#include <fstream>
#include <iostream>
#include <regex>
#include <ranges>
#include <algorithm>

#include "utils.h"

#define ITER 20

using namespace std;

int year2024_day11_puzzle3() {
    ifstream f("ressources/Year2024/day11/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    map<string, vector<string>> evolution;
    smatch sm;
    const regex regexp1(R"((\w+):)");
    const regex regexp2(R"((\w+),)");
    while (getline(f, s)) {
        s.insert(s.end(), ',');
        string key;
        vector<string> temp;
        if (regex_search(s, sm, regexp1)) {
            key = sm[1];
        }
        while (regex_search(s, sm, regexp2)) {
            temp.push_back(sm[1]);
            s = sm.suffix();
        }
        evolution[key] = temp;
    }

    vector<uint64_t> pops;
    for (const string& key : evolution | views::keys) {
        pops.push_back(runFullEvolution(ITER, evolution, key));
    }

    ranges::sort(pops);

    cout << pops[pops.size() - 1] - pops[0] << endl;
    return 0;
}
