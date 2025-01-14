#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <ranges>

using namespace std;

//uint64_t multiLcm(const map<int, vector<string>>& slotMachine);

int year2024_day16_puzzle3() {
    ifstream f("ressources/Year2024/day16/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    /*string s;
    smatch sm;
    const regex regexp1(R"((\d+))");
    const regex regexp2(R"((\w{3}|[^ \t\n\r\f\v]{3}|[ ]{4}))");

    vector<int> nbRotations;
    getline(f, s);
    while (regex_search(s, sm, regexp1)) {
        nbRotations.push_back(stoi(sm[1]));
        s = sm.suffix();
    }
    getline(f, s);

    map<int, vector<string>> slotMachine;
    while (getline(f, s)) {
        int col = 0;
        while (regex_search(s, sm, regexp2)) {
            if (sm[1] != "    ") slotMachine[col].push_back(sm[1]);
            s = sm.suffix();
            col++;
        }
    }

    map<int, int> pos;
    for (const int& key: slotMachine | views::keys) {
        pos[key] = 0;
    }

    uint64_t ppcmValue = multiLcm(slotMachine);
    cout << "ppcmValue:" << ppcmValue << endl;
    uint64_t coeff = static_cast<uint64_t>(202420242024) / ppcmValue;
    uint64_t missingTurns = static_cast<uint64_t>(202420242024) % ppcmValue;
    uint64_t nbCoins = 0;

    for (uint64_t i = 1; i <= ppcmValue; i++) {
        map<char, int> nbSymbols;
        for (auto &[key, value] : slotMachine) {
            nbSymbols[value[pos[key]][0]]++;
            nbSymbols[value[pos[key]][2]]++;
        }
        for (const int& i1 : nbSymbols | views::values) {
            if (i1 >= 3) nbCoins += i1 - 2;
        }

        for (auto &[key, value] : pos) {
            pos[key] = (value + nbRotations[key]) % slotMachine[key].size();
        }
    }

    uint64_t total = nbCoins * coeff;

    for (uint64_t i = 1; i <= missingTurns; i++) {
        for (auto &[key, value] : pos) {
            pos[key] = (value + nbRotations[key]) % slotMachine[key].size();
        }

        map<char, int> nbSymbols;
        for (auto &[key, value] : slotMachine) {
            nbSymbols[value[pos[key]][0]]++;
            nbSymbols[value[pos[key]][2]]++;
        }
        for (const int& i1 : nbSymbols | views::values) {
            if (i1 >= 3) total += i1 - 2;
        }
    }

    cout << "202420242024 = " << coeff << " * " << ppcmValue << " + " << missingTurns << endl;
    cout << "nbCoins: " << total << endl;*/

    return 0;
}

/*uint64_t multiLcm(const map<int, vector<string>>& slotMachine) {
    return accumulate(slotMachine.begin(), slotMachine.end(), 1, [](uint64_t acc, const auto& pair) {
        return lcm(acc, pair.second.size());
    });
}*/