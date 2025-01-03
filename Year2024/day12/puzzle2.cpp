#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include "utils.h"

#define HEIGHT 21
#define LENGTH 99

using namespace std;

int year2024_day12_puzzle2() {
    ifstream f("ressources/Year2024/day12/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    map<char, Pos> catapultes;
    map<Pos, int> targets;
    int line = 0;
    while (getline(f, s)) {
        line++;

        for (int i = 0; i < LENGTH; i++) {
            if (s[i] == 'T') {
                targets[{i, HEIGHT - line}] = 1;
            } else if (s[i] == 'H') {
                targets[{i, HEIGHT - line}] = 2;
            } else if (s[i] != '.' && s[i] != '=') {
                catapultes[s[i]] = {i, HEIGHT - line};
            }
        }
    }

    uint64_t totalPower = 0;

    for (Pos pos : targets | views::keys) {
        for (int power = 1; power < LENGTH / 2; power++) {
            for (const auto &[key, value] : catapultes) {
                if (checkIfHit(value, power, pos)) {
                    //cout << key << " hits a tower with power (" << power << ")" << endl;
                    totalPower += power * (key - '@') * targets[pos];
                }
            }
        }
    }

    cout << totalPower << endl;
    return 0;
}