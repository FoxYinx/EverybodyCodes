#include <fstream>
#include <iostream>
#include <regex>
#include <ranges>

using namespace std;

int year2024_day16_puzzle1() {
    ifstream f("ressources/Year2024/day16/part1.txt");

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

    for (auto &[key, value] : pos) {
        for (int i = 1; i <= 100; i++) {
            pos[key] = (value + nbRotations[key]) % slotMachine[key].size();
        }
    }

    for (auto &[key, value] : slotMachine) {
        cout << value[pos[key]] << " ";
    }

    return 0;
}
