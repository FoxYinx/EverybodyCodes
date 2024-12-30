#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int year2024_day11_puzzle1() {
    ifstream f("ressources/Year2024/day11/part1.txt");

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

    return 0;
}
