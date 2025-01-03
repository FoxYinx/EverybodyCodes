#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>

#define HEIGHT 5
#define LENGTH 33

using namespace std;

struct Pos {
    int x;
    int y;

    bool operator<(const Pos& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y > other.y;
    }

    bool operator==(const Pos& other) const {
        return x == other.x && y == other.y;
    }
};

bool checkIfHit(Pos start, const int& power, const Pos& end);

int year2024_day12_puzzle1() {
    ifstream f("ressources/Year2024/day12/part1.txt");

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
                    cout << key << " hits a tower with power (" << power << ")" << endl;
                    totalPower += power * (key - '@');
                }
            }
        }
    }

    cout << totalPower << endl;
    return 0;
}

bool checkIfHit(Pos start, const int& power, const Pos& end) {
    for (int j = 0; j < power; j++) {
        start.x++;
        start.y++;
        if (start == end) return true;
    }
    for (int j = 0; j < power; j++) {
        start.x++;
        if (start == end) return true;
    }
    while (start.y != 0) {
        start.x++;
        start.y--;
        if (start == end) return true;
    }
    return false;
}
