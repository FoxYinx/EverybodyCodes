#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Pos {
    int x;
    int y;
};

int year2024_day17_puzzle1() {
    ifstream f("ressources/Year2024/day17/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<Pos> stars;
    int line = 0;
    while(getline(f, s)) {
        for (int i = 0; i < s.size(); i++) if (s[i] == '*') stars.emplace_back(i, line);
    }

    cout << stars.size() << endl;
    return 0;
}
