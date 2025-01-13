#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <ranges>

using namespace std;

int multiLcm(const vector<int>& values);

int year2024_day16_puzzle2() {
    ifstream f("ressources/Year2024/day16/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    smatch sm;
    const regex regexp1(R"((\d+))");
    const regex regexp2(R"(([*^><-][_.:,][><*-^]| {4}))");

    vector<int> nbRotations;
    getline(f, s);
    while (regex_search(s, sm, regexp1)) {
        nbRotations.push_back(stoi(sm[1]));
        s = sm.suffix();
    }
    getline(f, s);

    map<int, vector<string>> slotMachine;
    while (getline(f, s)) {
        int col = 0;
        while (regex_search(s, sm, regexp2)) {
            if (sm[1] != "    ") slotMachine[col].push_back(sm[1]);
            s = sm.suffix();
            col++;
        }
    }

    map<int, int> pos;
    for (const int& key: slotMachine | views::keys) {
        pos[key] = 0;
    }

    int ppcmValue = multiLcm(nbRotations);
    uint64_t coeff = 202420242024 / static_cast<uint64_t>(ppcmValue);
    uint64_t nbCoins = 0;

    for (uint64_t i = 1; i <= 15; i++) {
        map<char, int> nbSymbols;
        for (auto &[key, value] : pos) {
            pos[key] = (value + nbRotations[key]) % slotMachine[key].size();
        }
        for (auto &[key, value] : slotMachine) {
            nbSymbols[value[pos[key]][0]]++;
            nbSymbols[value[pos[key]][2]]++;
        }
        for (const int& i : nbSymbols | views::values) {
            if (i >= 3) nbCoins += i - 2;
        }

        cout << "i=" << i << " , nbCoins=" << nbCoins << endl;
    }

    cout << nbCoins * coeff << endl;

    return 0;
}

int multiLcm(const vector<int>& values) {
    return accumulate(values.begin(), values.end(), 1, [](const int& a, const int& b) {
        return lcm(a, b);
    });
}