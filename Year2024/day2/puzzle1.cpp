#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int year2024_day2_puzzle1() {
    ifstream f("ressources/Year2024/day2/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<string> runes;
    getline(f, s);
    s.insert(s.end(),',');
    const regex regexp(R"((\w+),)");
    smatch sm;
    while (regex_search(s, sm, regexp)) {
        runes.push_back(sm[1]);
        s = sm.suffix();
    }
    getline(f, s);
    getline(f, s);

    int validRunes = 0;
    for (int i = 0; i < s.size(); i++) {
        for (const string& rune : runes) {
            if (s.size() - i >= rune.size() && rune == s.substr(i, rune.size())) validRunes++;
        }
    }

    cout << validRunes << endl;
    return 0;
}
