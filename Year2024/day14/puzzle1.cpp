#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int year2024_day14_puzzle1() {
    ifstream f("ressources/Year2024/day14/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    getline(f, s);
    smatch sm;
    const regex regexp(R"((\w)(\d+))");

    uint64_t currentHeight = 0;
    uint64_t maxHeight = 0;
    while (regex_search(s, sm, regexp)) {
        if (sm[1] == "U") {
            currentHeight += stoi(sm[2]);
        } else if (sm[1] == "D") {
            currentHeight -= stoi(sm[2]);
        }
        if (currentHeight > maxHeight) {
            maxHeight = currentHeight;
        }
        s = sm.suffix();
    }

    cout << maxHeight << endl;
    return 0;
}