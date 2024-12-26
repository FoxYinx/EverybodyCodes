#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int year2024_day2_puzzle3() {
    ifstream f("ressources/Year2024/day2/part3.txt");

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
    vector<string> plates = {};
    while (getline(f, s)) {
        plates.push_back(s);
    }

    int validRunes = 0;
    int depth = 0;
    vector flags(plates.size(), vector(plates[0].size(), false));
    for (const string& line : plates) {
        for (int i = 0; i < line.size(); i++) {
            for (const string& rune : runes) {
                string reversed_rune = rune;
                reverse(reversed_rune.begin(), reversed_rune.end());
                int rune_size = rune.size();
                int line_size = line.size();
                int plates_size = plates.size();
                for (int j = 0; j < rune_size; j++) {
                    if (rune == line.substr(i, min(rune_size, line_size - i)) + line.substr(0, max(0, rune_size - line_size + i)) ||
                        reversed_rune == line.substr(i, min(rune_size, line_size - i)) + line.substr(0, max(0, rune_size - line_size + i))) {
                        for (int k = 0; k < rune_size; k++) {
                            flags[depth][(i + k) % line_size] = true;
                        }
                        }
                }
                if (depth + rune_size <= plates_size) {
                    for (int j = 0; j < rune_size; j++) {
                        string vertical_word;
                        for (int k = 0; k < rune_size; k++) {
                            vertical_word += plates[depth + k][i];
                        }
                        if (rune == vertical_word || reversed_rune == vertical_word) {
                            for (int k = 0; k < rune_size; k++) {
                                flags[depth + k][i] = true;
                            }
                        }
                    }
                }
            }
        }
        depth++;
    }

    for (const auto& flag : flags) {
        for (const auto& fl : flag) {
            if (fl) validRunes++;
        }
    }

    cout << validRunes << endl;
    return 0;
}
