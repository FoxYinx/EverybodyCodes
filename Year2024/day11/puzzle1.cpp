#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#define ITER 4

using namespace std;

map<string, int> evol(const map<string, int>& termites, const map<string, vector<string>>& evolution);

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

    map<string, int> termites;
    termites["A"] = 1;

    for (int i = 0; i < ITER; i++) {
        termites = evol(termites, evolution);
    }

    int population = 0;
    for (const auto &[_, value] : termites) {
        population += value;
    }

    cout << population << endl;
    return 0;
}

map<string, int> evol(const map<string, int>& termites, const map<string, vector<string>>& evolution) {
    map<string, int> output;
    for (const auto &[key, value] : termites) {
        for (const string& toEvolve : evolution.at(key)) {
            output[toEvolve] += termites.at(key);
        }
    }
    return output;
}