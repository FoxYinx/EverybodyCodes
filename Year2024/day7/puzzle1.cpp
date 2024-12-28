#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <regex>

#define SEGMENTS 10

using namespace std;

struct Node {
    string name;
    int value;

    bool operator<(const Node& other) const {
        return value > other.value;
    }
};

int year2024_day7_puzzle1() {
    ifstream f("ressources/Year2024/day7/part1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\w+):)");
    const regex regexp2(R"((\+|\-|\=),)");
    smatch sm;
    map<string, vector<string>> devices;
    while (getline(f, s)) {
        s.insert(s.end(), ',');
        string key;
        if (regex_search(s, sm, regexp)) {
            key = sm[1];
        }
        vector<string> values;
        while (regex_search(s, sm, regexp2)) {
            values.push_back(sm[1]);
            s = sm.suffix();
        }
        devices[key] = values;
    }

    vector<Node> output;

    for (const auto &[key, value] : devices) {
        int result = 0;
        int temp = 10;
        for (int i = 0; i < SEGMENTS; i++) {
            const string& operateur = value[i % value.size()];
            if (operateur == "+") {
                temp++;
            } else if (operateur == "-") {
                if (temp > 0) temp--;
            } else if (operateur != "=") cerr << "Error parsing, got : " << operateur << endl;
            result += temp;
        }
        output.emplace_back(key, result);
    }

    sort(output.begin(), output.end());

    for (const auto&[name, _] : output) {
        cout << name;
    }

    return 0;
}
