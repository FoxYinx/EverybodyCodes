#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <regex>
#include "utils.h"

#define HEIGHT 8
#define LENGTH 22

using namespace std;

int year2024_day12_puzzle3() {
    ifstream f("ressources/Year2024/day12/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<Pos> meteors;
    const regex regexp(R"((\d+) (\d+))");
    smatch sm;
    while (getline(f, s)) {
        if (regex_search(s, sm, regexp)) {
            meteors.push_back({stoi(sm[1]) + 1, stoi(sm[2]) + 1});
        }
    }

    map<char, Pos> catapultes;
    catapultes['A'] = {1, 1};
    catapultes['B'] = {1, 2};
    catapultes['C'] = {1, 3};

    uint64_t totalPower = 0;

    for (Pos pos : meteors) {
        for (int power = 1; power < LENGTH / 2; power++) {
            for (const auto &[key, value] : catapultes) {
                if (checkIfHitMeteor(value, power, pos)) {
                    cout << key << " hits a meteor with power (" << power << ")" << endl;
                    totalPower += power * (key - '@');
                }
            }
        }
    }

    cout << totalPower << endl;
    return 0;
}