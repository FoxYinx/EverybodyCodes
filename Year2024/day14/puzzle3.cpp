#include <fstream>
#include <iostream>
#include <set>
#include <regex>
#include <queue>
#include <map>
#include <array>
#include <limits>
#include <ranges>

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

int bfs(const set<Pos>& tree, const Pos& start, set<Pos> leaves);

int year2024_day14_puzzle3() {
    ifstream f("ressources/Year2024/day14/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    smatch sm;
    const regex regexp(R"((\w)(\d+))");
    set<Pos> singularPos;
    set<Pos> leaves;

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
        leaves.emplace(currentX, currentY, currentZ);
    }

    int minimum = numeric_limits<int>::max();
    for (int i = 1; i <= 105; i++) {
        int temp = bfs(singularPos, {0, i, 0}, leaves);
        if (temp < minimum) {
            minimum = temp;
        }
    }

    cout << minimum << endl;
    return 0;
}

int bfs(const set<Pos>& tree, const Pos& start, set<Pos> leaves) {
    constexpr array<tuple<int, int, int>, 6> directions = {{{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}}};
    set<Pos> explored;
    explored.insert(start);
    int distance = 0;
    set<Pos> file;
    map<Pos, int> distances;
    file.insert(start);

    while (!leaves.empty() && !file.empty()) {
        set<Pos> newFile;
        for (const Pos& currentPos : file) {
            if (leaves.contains(currentPos)) {
                leaves.erase(currentPos);
                distances[currentPos] = distance;
                continue;
            }

            for (const auto &[dx, dy, dz] : directions) {
                int nx = currentPos.x + dx;
                int ny = currentPos.y + dy;
                int nz = currentPos.z + dz;
                if (tree.contains({nx, ny, nz}) && !explored.contains({nx, ny, nz})) {
                    newFile.emplace(nx, ny, nz);
                    explored.emplace(nx, ny, nz);
                }
            }
        }
        distance++;
        file = newFile;
    }

    int total = 0;
    for (const int& i : distances | views::values) {
        total += i;
    }
    return total;
}