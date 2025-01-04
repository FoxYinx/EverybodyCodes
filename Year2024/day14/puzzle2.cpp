#include <fstream>
#include <iostream>
#include <set>
#include <regex>

using namespace std;

struct Pos {
    int x;
    int y;
    int z;

    bool operator==(const Pos& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator<(const Pos& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

int year2024_day14_puzzle2() {
    ifstream f("ressources/Year2024/day14/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    smatch sm;
    const regex regexp(R"((\w)(\d+))");
    set<Pos> singularPos;

    while (getline(f, s)) {
        int currentX = 0;
        int currentY = 0;
        int currentZ = 0;
        while (regex_search(s, sm, regexp)) {
            if (sm[1] == "U") {
                for (int i = 0; i < stoi(sm[2]); i++) {
                    currentY++;
                    singularPos.emplace(currentX, currentY, currentZ);
                }
            } else if (sm[1] == "D") {
                for (int i = 0; i < stoi(sm[2]); i++) {
                    currentY--;
                    singularPos.emplace(currentX, currentY, currentZ);
                }
            } else if (sm[1] == "R") {
                for (int i = 0; i < stoi(sm[2]); i++) {
                    currentX++;
                    singularPos.emplace(currentX, currentY, currentZ);
                }
            } else if (sm[1] == "L") {
                for (int i = 0; i < stoi(sm[2]); i++) {
                    currentX--;
                    singularPos.emplace(currentX, currentY, currentZ);
                }
            } else if (sm[1] == "F") {
                for (int i = 0; i < stoi(sm[2]); i++) {
                    currentZ++;
                    singularPos.emplace(currentX, currentY, currentZ);
                }
            } else if (sm[1] == "B") {
                for (int i = 0; i < stoi(sm[2]); i++) {
                    currentZ--;
                    singularPos.emplace(currentX, currentY, currentZ);
                }
            } else {
                cerr << "Error parsing input, got : " << sm[1] << endl;
            }
            singularPos.emplace(currentX, currentY, currentZ);
            s = sm.suffix();
        }
    }

    cout << singularPos.size() << endl;
    return 0;
}