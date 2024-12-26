#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int year2024_day2_puzzle2() {
    ifstream f("ressources/Year2024/day2/part2.txt");

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

    int validRunes = 0;
    while (getline(f, s)) {
        vector flags(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (const string& rune : runes) {
                string reversed_rune = rune;
                reverse(reversed_rune.begin(), reversed_rune.end());
                if (s.size() - i >= rune.size() && (rune == s.substr(i, rune.size()) || reversed_rune == s.substr(i, rune.size()))) {
                    for (int j = 0; j < rune.size(); j++) {
                        flags[i + j] = true;
                    }
                }
            }
        }
        for (const auto& flag : flags) if (flag) validRunes++;
    }

    cout << validRunes << endl;
    return 0;
}
